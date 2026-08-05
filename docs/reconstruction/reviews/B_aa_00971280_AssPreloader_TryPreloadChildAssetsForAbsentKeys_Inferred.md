# Review B (skeptical / adversarial): `aa_00971280` AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971280` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-J) |
| **Counterpart** | `reviews/A_aa_00971280_AssPreloader_TryPreloadChildAssetsForAbsentKeys_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Decompiler `void FUN(int,int)` / plain RET | **Partially false** — epilogue is **`RET 8`** (two stack args confirmed at caller push pair) |
| 2 | Gate `*it == host+0xE0` means “type id match” | **Falsified** — `+0xE0` is tree **header/end** (`tree base +0xDC + 4`); body runs when key is **absent** |
| 3 | Always pushes fail ring | **Falsified** — fail path only when all child `vtbl+0xC` return 0 |
| 4 | Success writes only pending `+0x1c` | **Falsified** — success uses **`+0x4C`** stride-2 (`FUN_0043e970`), not W31-K pending `+0x1c` |
| 5 | CS always taken | **Falsified** — gated on `*(host+0x78)` / `*(host+0xA8)` |
| 6 | Product method name in body | **Overstated** — only file/line/format strings; method English **Inferred** |
| 7 | Key vec is GuardedVector | **Falsified** — flat `begin*/end*` at +4/+8, dword pointer step |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 + two stack args | **High** | Stack smash |
| Absent-tree gate | **High** | Process wrong key set |
| +0x4C success / +0x7C fail polarity | **High** | Corrupt preloader rings |
| Child vtbl+0xC contract | **Medium** | Wrong preload effect |
| Product method English | **Inferred** | Naming only |
| Nested drain/snapshot dual | **Open** | Incomplete port |
| Runtime | **Open** | CS / Sleep races |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  for key* in [begin,end):
    if lower_bound(host+0xDC) == end(host+0xE0):
      snapshot children from *(host+0x110)+0x28
      if any vtbl+0xC(key): push +0x4C pair; tree[key]=1
      else: log PRELOAD; push +0x7C
      Sleep(0); free local

bytes:
  RET C2 08 00
  LEA ECX,[EBP+0xDC] / CALL 0044a860 / CMP [EAX],ESI(= [EBP+0xE0])
  LEA EDI,[EBP+0x4C] / CALL 0043e970
  LEA EDI,[EBP+0x7C] / CALL 0043d670
  string assPreloader.cpp + "PRELOAD: unable to preload child asset %s"
```

Caller `FUN_00972140` @ `009722cd`: `push vec; push host; call` — dual stack args sealed.

---

## 4. Surviving contract for AutoCore

```
// AssPreloader try child preload for keys absent from host+0xDC tree:
//   stack host*, key_vec* (+4 begin*, +8 end*); RET 8; void
//   Success: stride-2 push host+0x4C {key, child_result}; tree value=1
//   Fail: log assPreloader.cpp:0x241; push host+0x7C
//   Optional CS: +0x60/+0x78 (success ring), +0x90/+0xA8 (fail ring)
// Do not confuse with pending enqueue +0x1c (W31-K).
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/offsets/polarity; product method English + nested dual residual → **accept-with-gaps**.
