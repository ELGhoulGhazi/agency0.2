## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = agency

agency_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
        verifier.c verifier.h \
        ajouter.c ajouter.h \ 
        reservation.c reservation.h

agency_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

