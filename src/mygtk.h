/*	mygtk.h
	Copyright (C) 2004-2007 Mark Tyler and Dmitry Groshev

	This file is part of mtPaint.

	mtPaint is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3 of the License, or
	(at your option) any later version.

	mtPaint is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with mtPaint in the file COPYING.
*/

#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

///	Generic RGB buffer

typedef struct {
	int x0, y0, x1, y1;
	unsigned char *rgb;
} rgbcontext;

///	Generic Widget Primitives

GtkWidget *add_a_window( GtkWindowType type, char *title, GtkWindowPosition pos, gboolean modal );
GtkWidget *add_a_button( char *text, int bord, GtkWidget *box, gboolean filler );
GtkWidget *add_a_spin( int value, int min, int max );
GtkWidget *add_a_table( int rows, int columns, int bord, GtkWidget *box );
GtkWidget *add_a_toggle( char *label, GtkWidget *box, gboolean value );
GtkWidget *add_to_table( char *text, GtkWidget *table, int row, int column, int spacing);
GtkWidget *spin_to_table( GtkWidget *table, int row, int column, int spacing,
	int value, int min, int max );
void add_hseparator( GtkWidget *widget, int xs, int ys );

void progress_init(char *text, int canc);		// Initialise progress window
int progress_update(float val);				// Update progress window
void progress_end();					// Close progress window

int alert_box( char *title, char *message, char *text1, char *text2, char *text3 );

// Add page to notebook

GtkWidget *add_new_page(GtkWidget *notebook, char *name);

// Slider-spin combo (practically a new widget class)

GtkWidget *mt_spinslide_new(gint swidth, gint sheight);
void mt_spinslide_set_range(GtkWidget *spinslide, gint minv, gint maxv);
gint mt_spinslide_get_value(GtkWidget *spinslide);
gint mt_spinslide_read_value(GtkWidget *spinslide);
void mt_spinslide_set_value(GtkWidget *spinslide, gint value);
/* void handler(GtkAdjustment *adjustment, gpointer user_data); */
void mt_spinslide_connect(GtkWidget *spinslide, GtkSignalFunc handler,
	gpointer user_data);
#define SPINSLIDE_ADJUSTMENT(s) \
	(GTK_SPIN_BUTTON(BOX_CHILD_1(s))->adjustment)
#define ADJ2INT(a) ((int)rint((a)->value))

// Self-contained package of radio buttons

GtkWidget *wj_radio_pack(char **names, int cnt, int vnum, int idx, int *var,
	GtkSignalFunc handler);

// Buttons for standard dialogs

GtkWidget *OK_box(int border, GtkWidget *window, char *nOK, GtkSignalFunc OK,
	char *nCancel, GtkSignalFunc Cancel);
GtkWidget *OK_box_add(GtkWidget *box, char *name, GtkSignalFunc Handler, int idx);

// Easier way with spinbuttons

int read_spin(GtkWidget *spin);
double read_float_spin(GtkWidget *spin);
GtkWidget *add_float_spin(double value, double min, double max);
void spin_connect(GtkWidget *spin, GtkSignalFunc handler, gpointer user_data);

// Box unpacking macros
#define BOX_CHILD_0(box) \
	(((GtkBoxChild*)GTK_BOX(box)->children->data)->widget)
#define BOX_CHILD_1(box) \
	(((GtkBoxChild*)GTK_BOX(box)->children->next->data)->widget)
#define BOX_CHILD_2(box) \
	(((GtkBoxChild*)GTK_BOX(box)->children->next->next->data)->widget)
#define BOX_CHILD(box, n) \
	(((GtkBoxChild *)g_list_nth_data(GTK_BOX(box)->children, (n)))->widget)

// Copy string quoting space chars

char *quote_spaces(const char *src);

// Wrapper for utf8->C translation

char *gtkncpy(char *dest, const char *src, int cnt);

// Wrapper for C->utf8 translation

char *gtkuncpy(char *dest, const char *src, int cnt);

// Generic wrapper for strncpy(), ensuring NUL termination

#define strncpy0(A,B,C) (strncpy((A), (B), (C))[(C) - 1] = 0)

// A more sane replacement for strncat()

char *strnncat(char *dest, const char *src, int max);

// Extracting widget from GtkTable

GtkWidget *table_slot(GtkWidget *table, int row, int col);

// Packing framed widget

GtkWidget *add_with_frame_x(GtkWidget *box, char *text, GtkWidget *widget,
	int border, int expand);
GtkWidget *add_with_frame(GtkWidget *box, char *text, GtkWidget *widget, int border);

// Entry + Browse

GtkWidget *mt_path_box(char *name, GtkWidget *box, char *title, int fsmode);

// Option menu

GtkWidget *wj_option_menu(char **names, int cnt, int idx, gpointer var,
	GtkSignalFunc handler);
int wj_option_menu_get_history(GtkWidget *optmenu);

// Workaround for broken option menu sizing in GTK2
#if GTK_MAJOR_VERSION == 2
void wj_option_realize(GtkWidget *widget, gpointer user_data);
#define FIX_OPTION_MENU_SIZE(opt) \
	gtk_signal_connect_after(GTK_OBJECT(opt), "realize", \
		GTK_SIGNAL_FUNC(wj_option_realize), NULL)
#else
#define FIX_OPTION_MENU_SIZE(opt)
#endif

// Set minimum size for a widget

void widget_set_minsize(GtkWidget *widget, int width, int height);
GtkWidget *widget_align_minsize(GtkWidget *widget, int width, int height);

// Signalled toggles

GtkWidget *sig_toggle(char *label, int value, gpointer var, GtkSignalFunc handler);
GtkWidget *sig_toggle_button(char *label, int value, gpointer var, GtkSignalFunc handler);

// Workaround for GtkCList reordering bug in GTK2

void clist_enable_drag(GtkWidget *clist);

// Properly destroy transient window

void destroy_dialog(GtkWidget *window);

// Settings notebook

GtkWidget *buttoned_book(GtkWidget **page0, GtkWidget **page1,
	GtkWidget **button, char *button_label);

// Most common use of boxes

GtkWidget *pack(GtkWidget *box, GtkWidget *widget);
GtkWidget *xpack(GtkWidget *box, GtkWidget *widget);

// Save/restore window positions

void win_store_pos(GtkWidget *window, char *inikey);
void win_restore_pos(GtkWidget *window, char *inikey, int defx, int defy,
	int defw, int defh);

// Eliminate flicker when scrolling

void fix_scroll(GtkWidget *scroll);

// Fix for paned widgets losing focus in GTK+1

#if GTK_MAJOR_VERSION == 1
void paned_mouse_fix(GtkWidget *widget);
#else
#define paned_mouse_fix(X)
#endif

// Init-time bugfixes for GTK+1 and GTK+2/Win32

#if (GTK_MAJOR_VERSION == 1) || defined GDK_WINDOWING_WIN32
void gtk_init_bugfixes();
#else
#define gtk_init_bugfixes()
#endif

// Moving mouse cursor

int move_mouse_relative(int dx, int dy);

// Mapping keyval to key

guint real_key(GdkEventKey *event);
guint low_key(GdkEventKey *event);
guint keyval_key(guint keyval);

// Interpreting arrow keys

int arrow_key(GdkEventKey *event, int *dx, int *dy, int mult);

// Focusable pixmap widget

GtkWidget *wj_fpixmap(int width, int height);
GdkPixmap *wj_fpixmap_pixmap(GtkWidget *widget);
void wj_fpixmap_draw_rgb(GtkWidget *widget, int x, int y, int w, int h,
	unsigned char *rgb, int step);
void wj_fpixmap_fill_rgb(GtkWidget *widget, int x, int y, int w, int h, int rgb);
void wj_fpixmap_move_cursor(GtkWidget *widget, int x, int y);
int wj_fpixmap_set_cursor(GtkWidget *widget, char *image, char *mask,
	int width, int height, int hot_x, int hot_y, int focused);
int wj_fpixmap_xy(GtkWidget *widget, int x, int y, int *xr, int *yr);
void wj_fpixmap_cursor(GtkWidget *widget, int *x, int *y);

// Menu-like combo box

GtkWidget *wj_combo_box(char **names, int cnt, int idx, gpointer var,
	GtkSignalFunc handler);
int wj_combo_box_get_history(GtkWidget *combobox);

// Bin widget with customizable size handling

GtkWidget *wj_size_bin();

// Disable visual updates while tweaking container's contents

gpointer toggle_updates(GtkWidget *widget, gpointer unlock);

// Filtering bogus xine-ui "keypresses" (Linux only)
#ifdef WIN32
#define XINE_FAKERY(key) 0
#else
#define XINE_FAKERY(key) (((key) == GDK_Shift_L) || ((key) == GDK_Control_L) \
	|| ((key) == GDK_Scroll_Lock) || ((key) == GDK_Num_Lock))
#endif

// Workaround for stupid GTK1 typecasts
#if GTK_MAJOR_VERSION == 1
#define GTK_RADIO_BUTTON_0(X) (GtkRadioButton *)(X)
#else
#define GTK_RADIO_BUTTON_0(X) GTK_RADIO_BUTTON(X)
#endif

// Path string sizes
/* If path is longer than this, it is user's own problem */
#define SANE_PATH_LEN 2048

#ifdef WIN32
#define PATHBUF 260 /* MinGW defines PATH_MAX to not include terminating NUL */
#elif defined MAXPATHLEN
#define PATHBUF MAXPATHLEN /* MAXPATHLEN includes the NUL */
#elif defined PATH_MAX
#define PATHBUF PATH_MAX /* POSIXly correct PATH_MAX does too */
#else
#define PATHBUF SANE_PATH_LEN /* Arbitrary limit for GNU Hurd and the like */
#endif
#if PATHBUF > SANE_PATH_LEN /* Force a sane limit */
#undef PATHBUF
#define PATHBUF SANE_PATH_LEN
#endif

#if GTK_VERSION_MAJOR == 1 /* Same encoding in GTK+1 */
#define PATHTXT PATHBUF
#else /* Allow for expansion when converting from codepage to UTF8 */
#define PATHTXT (PATHBUF * 2)
#endif
