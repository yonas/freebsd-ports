PORTNAME=	czkawka
DISTVERSION=	5.0.2
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multi functional app to find duplicates, empty folders, similar images etc.
WWW=		https://github.com/qarmin/czkawka

LICENSE=	CC-BY-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo gnome
USE_GITHUB=	yes
USE_GNOME=	gdkpixbuf2 gtk40
GH_ACCOUNT=	qarmin
PLIST_FILES=	bin/${PORTNAME}_cli \
		bin/${PORTNAME}_gui \
		share/applications/com.github.qarmin.czkawka.desktop \
		share/icons/hicolor/scalable/apps/com.github.qarmin.czkawka-symbolic.svg \
		share/icons/hicolor/scalable/apps/com.github.qarmin.czkawka.Devel.svg \
		share/icons/hicolor/scalable/apps/com.github.qarmin.czkawka.svg \
		share/metainfo/com.github.qarmin.czkawka.metainfo.xml \
		${NULL}

# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	${PLIST_FILES:Mbin/*:T}

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/*.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/data/icons/*.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${MKDIR} ${STAGEDIR}${PREFIX}/share/metainfo
	${INSTALL_DATA} ${WRKSRC}/data/*.metainfo.xml \
		${STAGEDIR}${PREFIX}/share/metainfo

.include <bsd.port.mk>
