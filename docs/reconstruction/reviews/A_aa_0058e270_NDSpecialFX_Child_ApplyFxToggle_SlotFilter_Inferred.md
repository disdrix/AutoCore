# Review A (reconstruction fidelity): `aa_0058e270` NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e270` |
| **VA** | `0x0058e270`–`0x0058e2f1` (**129 B**) |
| **Canonical name** | `NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred` |
| **Ghidra name** | `FUN_0058e270` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B W26-K) |
| **Reviewer role** | Reconstruction fidelity (clean ≡ raw ≡ live decompile ≡ bytes) |
| **Counterpart** | `reviews/B_aa_0058e270_NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred.md` |
| **System** | client-fx / NDSpecialFX child FX toggle |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Slot-filtered FX **stop then start** on an NDSpecialFX-owned child: match `slot_filter` against `child+0x25c` (wild byte `0xFF`), require slot ≠ `-1`, optional detach via `effect_stop`, optional attach via `effect_start` when link query returns 0; maintain active flag `+0x90f` bit0.

Exclusive callee of sealed `NDSpecialFX_ForEachOwnedBit7_ApplyFxToggle_Inferred` (`0x004b7030`) when `use_slot_filter != 0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058e270_FUN_0058e270.md` (+ 2026-07-29 W26-K append) |
| Annotated | `docs/reconstruction/raw/aa_0058e270_FUN_0058e270.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0058e270.cpp` |
| Named | `docs/reconstruction/reconstructed-exact/NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred.cpp` |
| Function | `docs/reconstruction/functions/aa_0058e270_FUN_0058e270.md` |
| Live | decompile ≡ raw CF; `read_memory` 129 B; bounds `0058e270`–`0058e2f1` |
| Sibling peek | `FUN_0058e300` (unrestricted gate `+0x25c < 0`) |
| Nested | W24-D `004b7030` exclusive caller |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 129 B + `ret 0x0C` | **Confirmed** | `C2 0C 00` ×2 exit paths |
| thiscall ECX = child | **Confirmed** | `mov esi,ecx` |
| Slot wild byte `0xFF` | **Confirmed** | `cmp al,0xFF` before push |
| Non-wild `movsx` vs `+0x25c` | **Confirmed** | |
| Skip if `+0x25c == -1` | **Confirmed** | |
| Stop: ECX=`effect_stop`, arg=`+0x914` | **Confirmed** | decomp flattens this |
| Start query ECX=`effect_start`, arg=`+0x258` | **Confirmed** | |
| Attach `0096dc80` + `\|1` early ret | **Confirmed** | |
| Clear bit0 fall-through | **Confirmed** | `and …,0xFE` |
| Exclusive caller `004b7030` | **Confirmed** | 1 xref |
| Product method name | **Inferred** | |
| Full 0096d* dual | Open | residual |

---

## 4. Control flow: clean ≡ raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| Slot gate (wild / match / skip -1) | **Yes** |
| Optional stop | **Yes** |
| Optional start + query | **Yes** |
| Success: set bit0 + return | **Yes** |
| Else clear bit0 | **Yes** |
| No-op when gate fails | **Yes** |

### 4.1 Sealed contract

```
// thiscall RET 0x0C
void NDSpecialFX_Child_ApplyFxToggle_SlotFilter_Inferred(
    void *child,
    void *effect_start,  // 0 = skip start
    void *effect_stop,   // 0 = skip stop
    int slot_filter);    // low byte; 0xFF wild

// if (sf==0xFF || child.slot==sext(sf)) && child.slot != -1:
//   if effect_stop:  0096d550(effect_stop, child+0x914)
//   if effect_start:
//     if 0096d460(effect_start, child+0x258)==0:
//       0096dc80(effect_start, child+0x258, child+0x914, child+0x254)
//       child+0x90f |= 1; return
//   child+0x90f &= ~1
```

### 4.2 Naming vs upstream duals

Upstream `004b7030` duals label stack args `want_start` / `want_stop`. Bytes prove non-zero values are **object pointers used as this** for particle helpers (not pure bools). Truthiness still gates; pointer value is the effect/controller. Clean uses `effect_start` / `effect_stop` for clarity while preserving CF.

---

## 5. Callers / callees (live)

| Dir | VA | Role |
|---|---|---|
| Caller | `0x004b7030` | Exclusive |
| Callee | `0x0096d550` | Detach/stop |
| Callee | `0x0096d460` | Link query |
| Callee | `0x0096dc80` | Attach/start |

---

## 6. Gaps

1. Product / PDB symbol.  
2. Full dual of `0096d550` / `0096d460` / `0096dc80`.  
3. Whether high bytes of `slot_filter` ever carry meaning (only low byte used).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept** — CF, ABI, slot gate, particle this-pointers, and exclusive caller sealed; product name inferred only.
