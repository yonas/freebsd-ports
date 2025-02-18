--- net/dns/dns_reloader.h.orig	2022-10-01 07:40:07 UTC
+++ net/dns/dns_reloader.h
@@ -7,7 +7,7 @@
 
 #include "build/build_config.h"
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_OPENBSD)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
 namespace net {
 
 // Call on the network thread before calling DnsReloaderMaybeReload() anywhere.
