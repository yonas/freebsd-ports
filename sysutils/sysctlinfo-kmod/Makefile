PORTNAME=	sysctlinfo-kmod
DISTVERSION=	20210222
CATEGORIES=	sysutils

MAINTAINER=	alfix86@gmail.com
COMMENT=	Kernel sysctl MIB-Tree interface
WWW=		https://gitlab.com/alfix/sysctlinfo

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		kmod
USE_GITLAB=	yes
GL_ACCOUNT=	alfix
GL_PROJECT=	sysctlinfo
GL_COMMIT=	0e32703fcde8d29df5e1f6f21094c668c61238fe

PLIST_FILES=	${KMODDIR}/sysctlinfo.ko \
		include/sysctlinfo.h \
		man/man3/sysctlinfo.3.gz \
		man/man4/sysctlinfo.4.gz

PORTEXAMPLES=	*

OPTIONS_DEFINE=		EXAMPLES
OPTIONS_DEFAULT=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400071
IGNORE=		uses struct sysctl_oid definition previous FreeBSD 1400071
.endif
.if ${OPSYS} != FreeBSD
IGNORE=		not supported on anything but FreeBSD
.endif

do-install:
	${INSTALL_KLD} ${WRKSRC}/sysctlinfo.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_DATA} ${WRKSRC}/sysctlinfo.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_MAN} ${WRKSRC}/sysctlinfo.3 ${STAGEDIR}${MAN3PREFIX}/man/man3
	${INSTALL_MAN} ${WRKSRC}/sysctlinfo.4 ${STAGEDIR}${MAN4PREFIX}/man/man4

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for e in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${e} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.post.mk>
