--- chrome/browser/prefs/browser_prefs.cc.orig	2022-10-29 17:50:56 UTC
+++ chrome/browser/prefs/browser_prefs.cc
@@ -439,14 +439,14 @@
 #include "components/os_crypt/os_crypt.h"
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/web_applications/url_handler_prefs.h"
 #include "components/device_signals/core/browser/pref_names.h"
 #endif
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
 #include "chrome/browser/browser_switcher/browser_switcher_prefs.h"
 #endif
@@ -474,7 +474,7 @@
 #include "chrome/browser/sessions/session_service_log.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/color/system_theme.h"
 #endif
 
@@ -1008,7 +1008,7 @@ void RegisterProfilePrefsForMigration(
   registry->RegisterIntegerPref(kProfileAvatarTutorialShown, 0);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Deprecated 08/2022.
   registry->RegisterBooleanPref(prefs::kUsesSystemThemeDeprecated, false);
 #endif
@@ -1238,7 +1238,7 @@ void RegisterLocalState(PrefRegistrySimple* registry) 
 #endif  // BUILDFLAG(GOOGLE_CHROME_BRANDING)
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   web_app::url_handler_prefs::RegisterLocalStatePrefs(registry);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
@@ -1555,13 +1555,13 @@ void RegisterProfilePrefs(user_prefs::PrefRegistrySync
   safe_browsing::PostCleanupSettingsResetter::RegisterProfilePrefs(registry);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   device_signals::RegisterProfilePrefs(registry);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD) || \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
   browser_switcher::BrowserSwitcherPrefs::RegisterProfilePrefs(registry);
 #endif
@@ -1975,7 +1975,7 @@ void MigrateObsoleteProfilePrefs(Profile* profile) {
   profile_prefs->ClearPref(kProfileAvatarTutorialShown);
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Added 08/2022.
   if (profile_prefs->HasPrefPath(prefs::kUsesSystemThemeDeprecated)) {
     auto migrated_theme =
