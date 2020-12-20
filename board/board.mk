# List of all the board related files.
BOARDSRC = $(BOARDDIR)/board.c

# Required include directories
BOARDINC = $(BOARDDIR)

# VBUS connection sensing is not available
BOARDDEFS = -DBOARD_OTG_NOVBUSSENS

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)

