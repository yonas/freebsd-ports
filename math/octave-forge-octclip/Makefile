PORTNAME=	octave-forge-octclip
PORTVERSION=	2.0.3
CATEGORIES=	math
MASTER_SITES=	https://bitbucket.org/jgpallero/octclip/downloads/
DISTNAME=	${OCTAVE_PKGNAME}-${DISTVERSIONFULL}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${DISTNAME}

WRKSRC=	${WRKDIR}/${OCTSRC}/src

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
