# Review B (skeptical / adversarial): `aa_00497a30` Ctx_ClearListTrackedOwnedAtScaledXY_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00497a30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-D) |
| **Counterpart** | `reviews/A_aa_00497a30_Ctx_ClearListTrackedOwnedAtScaledXY_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | cdecl / bare RET / void | **Falsified** — epilogue `mov eax,1; add esp,8; ret 8` |
| 2 | ECX is the host directly | **Falsified** — loads host via `*( *(ecx+0xC4) + 0xE898 )` |
| 3 | Scale constants are integers | **Falsified** — IEEE floats 32.0f / 0.0625f via `read_memory` |
| 4 | `DAT_00aefa50` is always 64 | **Falsified** — image currently **32.0f**; W30-Q rebuild may assign 64 or 32 |
| 5 | param_2 is row / param_3 is col | **Falsified by formula** — `index = (param_3/div)*dimX + (param_2/div)` ⇒ param_2 col-like, param_3 row-like |
| 6 | `operator_delete` noreturn skips zero/return | **Falsified** — hex zeros slot and returns 1 after delete |
| 7 | Divisor computed twice as decompiler shows | **Weakened** — bytes compute FPU product **once** then reuse ESI for both divides |
| 8 | Multiple static callers | **Falsified** — xref count 0 |
| 9 | Different owned type than rect helper | **Falsified** — same `FUN_004be2a0` + `elem+0x24` pattern |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Single-cell scaled clear role | **High** | Wrong port unit |
| Host indirection | **High** | Wrong this |
| Scale*0.0625 divisor | **High** | Wrong cell |
| XY formal order | **High** | Swapped axes |
| Product ctx English | **Low** | Naming |
| Static usage | **Open** | Dead code vs dynamic |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + constants + peer

```
// Image floats:
DAT_00aefa50 = 0x42000000 = 32.0f
DAT_00a14000 = 0x3d800000 = 0.0625f
// 32*0.0625 = 2; 64*0.0625 = 4

// Same owned teardown as aa_00494530 / Elem0x28@+0x24 (W29-F / W30-P).
// Host slot +0xE898 matches Class_009c7a1c factory store (W29-G).
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Decompiler `ROUND` is FPU-label; chop RC sealed by control-word patch in hex.

---

## 4. Surviving contract for AutoCore

```
// Port as ctx single-cell clearer:
uint32_t Ctx_ClearListTrackedOwnedAtScaledXY(void* ctx, uint32_t x, uint32_t y) {
  host = *(*(ctx+0xC4) + 0xE898);
  div  = trunc_toward_zero(scale_global * 0.0625f);
  index = (y/div)*host->dimX + (x/div);
  // dtor+delete owned@cell+0x24; always null; return 1
}
// Do not hardcode scale=32; read shared DAT_00aefa50 (or ported equivalent).
// ret 8 / thiscall. Orphan static graph — bind when call site found.
// Ignore Ghidra noreturn on operator_delete.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/host path/scale/index/owned teardown. Residual product English + orphan → **accept-with-gaps**.
