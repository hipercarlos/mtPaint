/*	help.c
	Copyright (C) 2004-2006 Mark Tyler

	This file is part of mtPaint.

	mtPaint is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.

	mtPaint is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with mtPaint in the file COPYING.
*/

int help_page_count = 4
;
char *help_page_titles[] = {
_("General"),
_("Keyboard shortcuts"),
_("Mouse shortcuts"),
_("Credits"),
NULL };

char *help_page_contents[] = {
_("\n"
"mtPaint 3.10 - Copyright (C) 2004-2006 The Authors\n"
"\n"
"See 'Credits' section for a list of the authors.\n"
"\n"
"mtPaint is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.\n"
"\n"
"mtPaint is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.\n"
"\n"
"mtPaint is a simple GTK+1/2 painting program designed for creating icons and pixel based artwork. It can edit indexed palette or 24 bit RGB images and offers basic painting and palette manipulation tools. It also has several other more powerful features such as channels, layers and animation. Due to its simplicity and lack of dependencies it runs well on GNU/Linux, Windows and older PC hardware.\n"
"\n"
"There is full documentation of mtPaint's features contained in a handbook.  If you don't already have this, you can download it from the mtPaint website.\n"
"\n"
"If you like mtPaint and you want to keep up to date with new releases, or you want to give some feedback, then the mailing lists may be of interest to you:\n"
"\n"
"http://sourceforge.net/mail/?group_id=155874\n"
),
_("\n"
"  Ctrl-N            Create new image\n"
"  Ctrl-O            Open Image\n"
"  Ctrl-S            Save Image\n"
"  Ctrl-Q            Quit program\n"
"\n"
"  Ctrl-A            Select whole image\n"
"  Escape            Select nothing, cancel paste box\n"
"  Ctrl-C            Copy selection to clipboard\n"
"  Ctrl-X            Copy selection to clipboard, and then paint current pattern to selection area\n"
"  Ctrl-V            Paste clipboard to centre of current view\n"
"  Ctrl-K            Paste clipboard to location it was copied from\n"
"  Enter/Return      Commit paste to canvas\n"
"\n"
"  Arrow keys        Paint Mode - Move the mouse pointer\n"
"  Arrow keys        Selection Mode - Nudge selection box or paste box by one pixel\n"
"  Shift+Arrow keys  Nudge mouse pointer, selection box or paste box by x pixels - x is defined by the Preferences window\n"
"  Ctrl+Arrows       Move layer or resize selection box\n"
"\n"
"  [ or ]            Change colour A to the next or previous palette item\n"
"  Shift+[ or ]      Change colour B to the next or previous palette item\n"
"\n"
"  Delete            Crop image to selection\n"
"  Insert            Transform colours - i.e. Brightness, Contrast, Saturation, Posterize, Gamma\n"
"  Ctrl-G            Greyscale the image\n"
"  Shift-Ctrl-G      Greyscale the image (Gamma corrected)\n"
"\n"
"  Ctrl-T            Draw a rectangle around the selection area with the current fill\n"
"  Ctrl-Shift-T      Fill in the selection area with the current fill\n"
"  Ctrl-L            Draw an ellipse spanning the selection area\n"
"  Ctrl-Shift-L      Draw a filled ellipse spanning the selection area\n"
"\n"
"  Ctrl-E            Edit the RGB values for colours A & B\n"
"  Ctrl-W            Edit all palette colours\n"
"\n"
"  Ctrl-P            Preferences\n"
"  Ctrl-I            Information\n"
"\n"
"  Ctrl-Z            Undo last action\n"
"  Ctrl-R            Redo an undone action\n"
"\n"
"  C                 Command Line Window\n"
"  V                 View Window\n"
"  L                 Layers Window\n"
"\n"
"  +,=               Main edit window - Zoom in\n"
"  -                 Main edit window - Zoom out\n"
"  Shift +,=         View window - Zoom in\n"
"  Shift -           View window - Zoom out\n"
"\n"
"  1                 10% zoom\n"
"  2                 25% zoom\n"
"  3                 50% zoom\n"
"  4                 100% zoom\n"
"  5                 400% zoom\n"
"  6                 800% zoom\n"
"  7                 1200% zoom\n"
"  8                 1600% zoom\n"
"  9                 2000% zoom\n"
"\n"
"  Shift + 1         Edit image channel\n"
"  Shift + 2         Edit alpha channel\n"
"  Shift + 3         Edit selection channel\n"
"  Shift + 4         Edit mask channel\n"
"\n"
"  F1                Help\n"
"  F2                Choose Pattern\n"
"  F3                Choose Brush\n"
"  F4                Paint Tool\n"
"  F5                Toggle Main Toolbar\n"
"  F6                Toggle Tools Toolbar\n"
"  F7                Toggle Settings Toolbar\n"
"  F8                Toggle Palette\n"
"  F9                Selection Tool\n"
"\n"
"  Ctrl + F1 - F12   Save current clipboard to file 1-12\n"
"  Shift + F1 - F12  Load clipboard from file 1-12\n"
"\n"
"  Ctrl + 1, 2, ... , 0  Set opacity to 10%, 20%, ... , 100% (main or keypad numbers)\n"
"  Ctrl + + or =     Increase opacity by 1%\n"
"  Ctrl + -          Decrease opacity by 1%\n"
"\n"
"  Home              Show or hide main window menu/toolbar/status bar/palette\n"
"  Page Up           Scale Image\n"
"  Page Down         Resize Image canvas\n"
"  End               Pan Window\n"
),
_("\n"
"  Left button          Paint to canvas using the current tool\n"
"  Middle button        Selects the point which will be the centre of the image after the next zoom\n"
"  Right button         Commit paste to canvas / Stop drawing current line / Cancel selection\n"
"\n"
"  Scroll Wheel         In GTK+2 the user can have the scroll wheel zoom in or out via the Preferences window\n"
"\n"
"  Ctrl+Left button     Choose colour A from under mouse pointer\n"
"  Ctrl+Right button    Choose colour B from under mouse pointer\n"
"  Ctrl+Scroll Wheel    Scroll the main edit window left or right\n"
"\n"
"  Shift+Right button   Selects the point which will be the centre of the image after the next zoom\n"
"\n"
"\n"
"You can fixate the X/Y co-ordinates while moving the mouse:\n"
"\n"
"  Shift                Constrain mouse movements to vertical line\n"
"  Shift+Ctrl           Constrain mouse movements to horizontal line\n"
),
_("\n"
"mtPaint is maintained by Dmitry Groshev.\n"
"\n"
"wjaguar@mail.ru\n"
"http://mtpaint.sourceforge.net/\n"
"\n"
"The following people (in alphabetical order) have contributed directly to the project, and are therefore worthy of gracious thanks for their generosity and hard work:\n"
"\n"
"\n"
"Authors\n"
"\n"
"Dennis Lee - Wrote the two quantizing methods DL1 & 3 - see quantizer.c for more information.\n"
"Dmitry Groshev - Contributing developer for version 2.30. Lead developer and maintainer from version 3.00 to the present.\n"
"Magnus Hjorth - Wrote inifile.c/h, from mhWaveEdit 1.3.0.\n"
"Mark Tyler - Original author and maintainer up to version 3.00, occasional contributor thereafter.\n"
"Xiaolin Wu - Wrote the Wu quantizing method - see wu.c for more information.\n"
"\n"
"\n"
"General Contributions (Feedback and Ideas for improvements unless otherwise stated)\n"
"\n"
"Abdulla Al Muhairi - Website redesign April 2005\n"
"Alan Horkan\n"
"Alexandre Prokoudine\n"
"Antonio Andrea Bianco\n"
"Ed Jason\n"
"Eddie Kohler - Created Gifsicle which is needed for the creation and viewing of animated GIF files http://www.lcdf.org/gifsicle/\n"
"Guadalinex Team (Junta de Andalucia) - man page, Launchpad/Rosetta registration\n"
"Lou Afonso\n"
"Magnus Hjorth\n"
"Martin Zelaia\n"
"Pavel Ruzicka\n"
"Puppy Linux (Barry Kauler)\n"
"Vlastimil Krejcir\n"
"William Kern\n"
"\n"
"\n"
"Translations\n"
"\n"
"Brazilian Portuguese - Paulo Trevizan\n"
"Czech - Pavel Ruzicka\n"
"French - Nicolas Velin, Pascal Billard\n"
"German - Oliver Frommel\n"
"Polish - Simek\n"
"Portuguese - Israel G. Lugo\n"
"Spanish - Guadalinex Team (Junta de Andalucia), Antonio San\n"
"Taiwanese Chinese - Wei-Lun Chao\n"
"Turkish - Muhammet Kara, Tutku Dalmaz\n"
),
NULL };
