PORTNAME=	texworks
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.6.2
PORTREVISION=	46
CATEGORIES=	editors

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Simple TeX front-end program
WWW=		https://www.tug.org/texworks/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	hunspell:textproc/hunspell
LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5

USES=		compiler:c++11-lang cmake desktop-file-utils pkgconfig \
		qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	TeXworks
USE_QT=		buildtools:build designer:build qmake:build \
		core concurrent dbus gui linguisttools script \
		scripttools uitools widgets xml

USE_TEX=	synctex
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DTeXworks_DIC_DIR:PATH=${LOCALBASE}/share/hunspell \
		-DTeXworks_DOCS_DIR:PATH=${DOCSDIR_REL} \
		-DTeXworks_HELP_DIR:PATH=${DOCSDIR_REL} \
		-DTeXworks_MAN_DIR:PATH=man/man1

PORTDOCS=	*
PLIST_FILES=	bin/texworks \
		man/man1/texworks.1.gz \
		share/appdata/texworks.appdata.xml \
		share/applications/texworks.desktop \
		share/pixmaps/TeXworks.png

OPTIONS_DEFINE=	DOCS LUA PYTHON

LUA_USES=		lua
LUA_CMAKE_BOOL=		WITH_LUA
LUA_PLIST_FILES=	lib/texworks/libTWLuaPlugin.so

PYTHON_USES=		python:3.4+
PYTHON_CMAKE_BOOL=	WITH_PYTHON
PYTHON_PLIST_FILES=	lib/texworks/libTWPythonPlugin.so

post-patch:
	@${FIND} ${WRKSRC}/src -type f | ${XARGS} ${REINPLACE_CMD} 's|synctex_next_result|synctex_scanner_next_result|g'

.include <bsd.port.mk>
