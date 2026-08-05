# Review A (reconstruction fidelity): `aa_004b2910` Color_LerpU8x3_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b2910` |
| **VA** | `0x004b2910`–`0x004b29cd` (190 B / `0xBE`) |
| **Canonical name** | `Color_LerpU8x3_Inferred` (structural; product/PDB open) |
| **Ghidra name** | `FUN_004b2910` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual W28-E) |
| **Counterpart** | `reviews/B_aa_004b2910_Color_LerpU8x3_Inferred.md` |
| **System** | client color / object-motion stage params |
| **Verdict** | **accept-with-gaps** — CF + ABI + 3-channel ROUND lerp sealed; product field English open |
| **Dual status** | **Present (first full dual)** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `get_function_by_address` + `read_memory` + callers/callees/xrefs. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Leaf helper: lerp **three U8 channels** with ROUND.

```
out[i] = from[i] + ROUND((to[i] - from[i]) * t)   // i = 2, 1, 0
```

No alpha. Sole caller is sealed `ObjectMotion_ApplyStageParams_Inferred` (dirty RNG color pick + continuous progress lerp).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live decompile | full body @ `0x004b2910` |
| Bounds | `get_function_by_address` → `004b2910`–`004b29cd` |
| Entry/exit bytes | `read_memory` full 190 B; epilogue `5F 88 16 5E C3` |
| Callers | `FUN_004b2b90` ×3; each followed by `83 C4 10` |
| Peer dual | ApplyStageParams (W27-E) — sole consumer |
| Raw / annotated / clean | W28-E updated |

**Not performed:** Launcher, runtime golden, bit-exact.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range `004b2910`–`004b29cd` (190 B) | **Confirmed** | `get_function_by_address` + full-body read |
| cdecl 4 stack args; plain `RET` | **Confirmed** | epilogue `C3`; callers `add esp,10` |
| Void (no AL contract) | **Confirmed** | decompile returns; no EAX set for bool |
| Channel order 2→1→0 | **Confirmed** | decompile + movzx/sub/mulss blocks |
| ROUND on signed byte delta × t | **Confirmed** | FPU path + ROUND |
| Exactly 3 channels (no alpha) | **Confirmed** | three blocks only |
| Sole caller ApplyStageParams | **Confirmed** | xrefs ×3 all in `004b2b90` |
| Product color-slot English | **Open** | stage offsets only |
| Runtime / differential | **Open** | |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| Load to/from ch2; delta; ×t; ROUND; store out[2] | Yes |
| Same for ch1 | Yes |
| Same for ch0 | Yes |
| pop esi/edi; plain ret | Yes |
| No fourth channel / no early-out | Yes |

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `FUN_004b2b90` | `0x004b2df5` | dirty; RNG t; → `slot+0xd` |
| `FUN_004b2b90` | `0x004b2e52` | dirty; RNG t; → `slot+0x47` |
| `FUN_004b2b90` | `0x004b313d` | continuous; progress t; baseline→end → `slot+0xd` |

---

## 6. Gaps

1. Retail / PDB symbol.
2. Product English for the three-byte stage/slot color fields.
3. Runtime golden for ROUND edge cases (t∉[0,1], from>to).

**Verdict:** **accept-with-gaps** — sealed leaf lerp CF and cdecl ABI; field English open.
