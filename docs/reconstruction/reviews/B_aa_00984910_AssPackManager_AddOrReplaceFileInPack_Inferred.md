# Review B (skeptical / adversarial): `aa_00984910` AssPackManager_AddOrReplaceFileInPack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984910` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-Q) |
| **Counterpart** | `reviews/A_aa_00984910_AssPackManager_AddOrReplaceFileInPack_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Thiscall ECX=this (host) | **Falsified** — ECX is **srcPath** (`8B F1`); host is **stack0** |
| 2 | Bare `RET` / fewer than 5 stack args | **Falsified** — `C2 14 00` (5 dwords); both callers push 5 |
| 3 | Always replaces | **Falsified** — `forceReplace==0` + mtime/size/type match → return **1** "Not replacing" |
| 4 | Always locks | **Falsified** — gate `char +0x50` |
| 5 | Same as extract `FUN_00984d30` | **Falsified** — add/replace into pack vs extract-to-file |
| 6 | Compact decompile shows ECX=host | **Falsified** — call-site bytes set ECX to path; host pushed |
| 7 | Scaffold name is product method | **Careful** — plate only; `_Inferred` required |
| 8 | Return always 0 | **Falsified** — 1 skip, −1 fail, else add rc |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ECX path + 5 stack + RET 0x14 | **High** | Wrong port convention |
| Skip vs replace vs add CF | **High** | Corrupt pack / silent skip |
| CS offsets | **High** | Deadlock / race |
| Compress/insert nested | **Med** | Wrong meta layout |
| arg4 meaning | **Low** | Unused formal mis-port |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Caller FUN_00984c70 @ 0x00984ce5 (dir bulk add):
//   ECX = leaf path c_str
//   push ebx; push ebx; push 1; push edi; push ebp
//   call FUN_00984910   // force=1 always

// Caller FUN_00985010 @ 0x00985198 (compact):
//   ECX = joined stage path
//   push c_str; push 0; push 1; push typeId; push packB
//   call FUN_00984910
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Full 854 B hex seals epilogue.

---

## 4. Surviving contract for AutoCore

```
// Port as pack ADD/REPLACE under optional CS:
//   srcPath in ECX; host, typeId, forceReplace, arg4, replaceCookie on stack
//   if exists && !force && same mtime/size/type → log Not replacing; return 1
//   else replace-prep; open-read; compress; insert; log Added; return rc
// Do not invent thiscall-ECX=host.
// Do not treat as extract (that's 00984d30).
// Pair with CompactPackFile + dir bulk-add FUN_00984c70.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/skip-add. Nested compress + arg4 residual → **accept-with-gaps**.
