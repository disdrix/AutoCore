# Review B (skeptical / adversarial): `aa_0076adc0` Fs_PathIsDirectory_Stat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076adc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-C) |
| **Counterpart** | `reviews/A_aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md` |
| **Scratch** | `tmp/a_0076adc0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is `GetFileAttributes` / Win32 attrib probe | **Falsified** — sole callee is CRT `stat` IAT; no kernel32 attrib API |
| 2 | Returns full `st_mode` | **Falsified** — `SHR 14; AND 1` yields bool only |
| 3 | Fail return preserves `stat` errno in EAX | **Falsified** — `XOR AL,AL` forces 0; decompiler `uVar4 & 0xffffff00` is misleading |
| 4 | thiscall / ECX path | **Falsified** — stack formal only; bare `RET` |
| 5 | Trailing sep strip is recursive/multi | **Falsified** — single last-char test only |
| 6 | Product name sealed | **Careful** — structural `_Inferred` only |
| 7 | Exists-as-file also true | **Falsified** — non-dir existing paths return 0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| is_directory bool via S_IFDIR | **High** | Wrong FS gate in recurse/list |
| cdecl 1-arg bare RET | **High** | ABI crash |
| Fail → 0 | **High** | Treat missing path as dir |
| st_mode @ +6 | **High** | Wrong bit if layout misread |
| Product plate | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// W32-D Fs_DirRecurseCollectLeafPaths:
//   if (FUN_0076adc0(path) == 0) return -1;
// W33-C peer FUN_0076b3f0:
//   if (FUN_0076adc0(path)) pattern += "/*";
// Body 118 B; dual ADD ESP,0x128; RET; pad CC
// Live decompile 2026-07-29 ≡ raw 2026-07-23 CF
```

---

## 4. Surviving contract for AutoCore

```
// Port as pure is_directory helper:
bool Fs_PathIsDirectory_Stat(const char* path) {
  char buf[260];
  copy_and_strip_trailing_sep(buf, path);
  struct stat st;
  if (stat(buf, &st) != 0) return false;
  return (st.st_mode & S_IFDIR) != 0;  // equiv (mode>>14)&1 on MSVC
}
// cdecl; do not invent Win32 attributes path.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/S_IFDIR/fail-zero. Residual product/CRT demangle only → **accept-with-gaps**.
