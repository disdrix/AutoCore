# Review B (skeptical / adversarial): `aa_004c3a40` CVOGObject_SetLocalPosition4_Gated_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004c3a40` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/A_aa_004c3a40_CVOGObject_SetLocalPosition4_Gated_Inferred.md` |
| **Scratch** | `reviews/a_004c3a40.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Primary purpose is `"VOG_DEBUG_STOP"` / fatal halt | Scaffold `Named_VOG_DEBUG_STOP_*` | **Falsified** — trap is side-path; store is main work; arg0=`0` makes logger a **no-op** |
| 2 | NaN aborts the write | Early-return intuition | **Falsified** — trap falls through; gate still evaluated; store may still run |
| 3 | NaN checks all 4 floats | Vec4 completeness | **Falsified** — only indices 0..2; W unchecked |
| 4 | Same gate object as SetSteer (`wobj` ptr + `+0xb4`) | Shared 0xC7 folklore | **Falsified** — this tests **component byte `+0xb8`**, no ptr load, no null-allows-write arm |
| 5 | Writes thr / steer / HB | DriveControlTick association | **Falsified** — only leaf stores `+0x240..24c` |
| 6 | Inlines the 4 stores | "Simple setter" | **Partial falsify** — body delegates to `FUN_004cb3e0` (still only path from this unit) |
| 7 | Mask `199` is decompiler decimal noise | Trust hex only | **Falsified** — imm8 `0xC7` on `TEST byte ptr […+0xb8],0xc7` |
| 8 | Trap always logs | String presence | **Falsified** — `FUN_007a4480` requires arg0==`1` for `_vsnprintf`+log |
| 9 | Getter mask equals write mask | Sibling symmetry | **Falsified as equal** — getter uses `& 7`, write uses `& 0xC7` |
| 10 | DCT is sole caller | Drive-centric view | **Falsified** — also `FUN_0091a5f0`×2 and `FUN_005cc7c0` |
| 11 | `FUN_004cb3e0` exclusive to this unit | Leaf ownership | **Falsified as exclusive** — also called from `FUN_005cd3b0` (ungated leaf from that site) |
| 12 | Product name sealed | Inferred rename | **Not sealed** — keep `_Inferred` / Ghidra `FUN_*` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body CF / span / ABI `ret 4` | **High** | Wrong port signature |
| NaN xyz + fall-through | **High** | Port early-outs lose valid writes after NaN noise |
| Trap no-op when arg0=0 | **High** | Fake "debug break" in server port |
| Gate home `typeOff+0xb8` + mask `0xC7` | **High** | Wrong lock / free pose under suppress |
| Store layout `+0x240..24c` | **High** | Corrupt wrong fields |
| Sibling getter linkage | **High** | Read/write asymmetry bugs |
| Caller inventory (4 sites) | **High** | Miss look/AI writers |
| Bypass leaf via `005cd3b0` | **High** (existence) | "Always gated" port false |
| Product English name | **Low** | Naming only |
| Bit producers / `+0xb8` English | **Low–Med** | Full suppress parity |
| Semantic "position" vs generic vec4 | **Probable** | Mislabel; consumers treat as pos via rb `+0xb0` parallel |

---

## 3. Cross-check against raw + instructions

```
; sealed 2026-07-29 three-rep (decompile / force_decompile / disassemble)
isnan(in[0]) || isnan(in[1]) || isnan(in[2]) → FUN_007a4480(0,"VOG_DEBUG_STOP")
// always continues:
typeOff = *(*(this+4)+4);
if ( (*(u8*)(this + typeOff + 0xb8) & 0xC7) == 0 )
    FUN_004cb3e0(this, in);   // +0x240..+0x24c
ret 4
```

Live ≡ raw scaffold body. Prior alias overweighted the debug string; dual corrects role to **gated local pos4 store**.

---

## 4. Surviving contract for AutoCore

```
SetLocalPosition4_Gated(object, in /* float[4] */):
  if any of in[0..2] is NaN:
      DebugStop_NoOp("VOG_DEBUG_STOP")   // retail: FUN_007a4480(0, ...)
  typeOff = *(*(object+4)+4)
  if ( (object[typeOff + 0xb8] & 0xC7) == 0 )
      object[+0x240 .. +0x24c] = in[0..3]   // via FUN_004cb3e0
  // else retain prior +0x240 block

// Sibling read (FUN_004c3ac0):
//   if (flags&7)==0 → &object[+0x240]
//   else phys rb+0xb0 or embedded typeOff+0x84

// Contrast SetSteerInput:
//   wobj = *(object+typeOff+0xb0); gate wobj==0 || (wobj+0xb4 & 0xC7)==0 → +0x618

// Callers of interest:
//   DriveControlTick (post terrain helper, sets +0x304)
//   FUN_0091a5f0 look apply (×2)
//   FUN_005cc7c0 host path

// Bypass (ungated leaf):
//   FUN_005cd3b0 → FUN_004cb3e0 directly
```

**Port tests that matter:**

* Under any `0xC7` bit set on component `+0xb8`, this setter must **not** change `+0x240..24c`.
* NaN in x/y/z must **not** by itself prevent a subsequent open-gate store in the same call (retail falls through).
* W may be non-finite without tripping the trap.
* `FUN_005cd3b0` (or other leaf callers) may still write `+0x240` without this gate — do not assume all pose writes are gated.
* Do not implement trap as `abort`/`__debugbreak` for arg0=0.

---

## 5. Open questions

1. Runtime CE force of `+0xb8` bits and NaN vectors (matrix policy).
2. Producers of `0xC7` bits / component type identity (**UF open — not invented**).
3. Full reader set for `+0x240` and meaning of `object+0x304` flag set by callers.
4. Product rename when RTTI/string recovered.
5. Dual residual on `FUN_0091a5f0` / `FUN_004cff70` (OWN other VAs).

**Verdict:** **accept-with-gaps** — adversarial checks clear structural overclaims; static CF High; not complete.
