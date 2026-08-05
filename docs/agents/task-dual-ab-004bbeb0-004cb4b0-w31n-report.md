# Dual A/B report — W31-N OWN `aa_004bbeb0` + `aa_004cb4b0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W31-N  
**Scope:** VAs `0x004bbeb0`, `0x004cb4b0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave31_partition_map.md` (W31-N).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bbeb0` Host_ResetHashQueuesVectors_Inferred | **accept-with-gaps** — ABI/CF/ECX targets/tail-JMP/log2=5 sealed; product host English residual |
| `aa_004cb4b0` StdMap_LowerBound_Tfid_Isnil29 | **accept-with-gaps** — leaf lower_bound CF/ABI/isnil29/key layout sealed; product map type residual |

---

## VA `0x004bbeb0` — sealed facts

1. **Body:** `0x004bbeb0`–`0x004bbf18` exclusive (**104 B** / `0x68`); pad `CC` then `FUN_004bbf20`.
2. **ABI:** **ECX=`this`** (`56 8B F1`); bare **`RET`** (`C3`); void. Flag@`+0x0d` path is **tail JMP** `vtbl[+4]` (`FF 62 04`).
3. **Semantics (bytes authority over decompiler this-loss):**
   - `CNDHash_Recreate_009cb450` (`FUN_004bcce0`) on **`*(this+0x18)`** with **log2=5** always (W30-G sole consumer).
   - `FUN_004bc580` drain on **`*(this+0x1c)`**, **`*(this+0x20)`**, **`*(this+0x24)`**.
   - `FUN_00410420(0,0)` clear embedded dword vectors at **`this+0x48`**, **`+0x28`**, **`+0x38`**.
   - If flag@`+0x0c`: **CALL** `(*(this+4))->vtbl[+4]`.
   - If flag@`+0x0d`: **tail** `(*(this+8))->vtbl[+4]`.
4. **Classification:** worker.
5. **Callers:** `FUN_004d98f0` @ `0x004d9a61`; `FUN_00943b80` @ `0x00943d72` (post object-sweep teardown).
6. **Callees:** `FUN_004bcce0`, `FUN_004bc580`×3, `FUN_00410420`×3; conditional vtbl[+4].
7. **Name:** `Host_ResetHashQueuesVectors_Inferred` (Ghidra `FUN_004bbeb0`; **Inferred** structural). Reject scaffold `Named_CalleeOf_Named_CalleeOf_Named_Server_needs_an_update_*`.
8. **Decompile ≡ stage list**; **bytes win** on ECX targets + tail JMP (decompiler “jumptable” warn is false).  
   Full hex: raw W31-N append (104 B).

### Gaps

- Product/PDB host class + global identity at call sites.  
- Queue / vector / iface product English.  
- Nested `FUN_004bc580` / `FUN_00410420` not OWN.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bbeb0_Host_ResetHashQueuesVectors_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bbeb0_Host_ResetHashQueuesVectors_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004bbeb0_FUN_004bbeb0.md` |
| Annotated | `docs/reconstruction/raw/aa_004bbeb0_FUN_004bbeb0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Host_ResetHashQueuesVectors_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bbeb0.cpp` |
| Function | `docs/reconstruction/functions/aa_004bbeb0_FUN_004bbeb0.md` |
| Function named | `docs/reconstruction/functions/aa_004bbeb0_Host_ResetHashQueuesVectors_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004bbeb0.md` |

---

## VA `0x004cb4b0` — sealed facts

1. **Body:** `0x004cb4b0`–`0x004cb4eb` exclusive (**59 B** / `0x3B`); pad `CC`.
2. **ABI:** **thiscall** ECX=map host (`head@+4`); stack **`const KeyU32I32*`**; epilogue **`RET 4`** (`C2 04 00`); returns **node*** in EAX.
3. **Semantics:** MSVC **`_Tree::_Lbound`** for 8-byte key `(uint32 lo, int32 hi)`:
   - Root = `head->parent`; stop on **isnil@+0x29**.
   - Key at **node+0x10 / +0x14**; compare hi signed then lo unsigned.
   - Go left + remember when `search <= node.key`; else right.
   - Return candidate (may be head/end). **No** equality gate.
4. **Classification:** leaf.
5. **Callers:** `FUN_004c8970`, `FUN_004ca760`, `FUN_004cba00`, `FUN_004cc400`, `FUN_005a0470` (find/insert/erase shells; Object map often host@`+0x154` / head@`+0x158`).
6. **Callees:** none.
7. **Name:** `StdMap_LowerBound_Tfid_Isnil29` (Ghidra `FUN_004cb4b0`; **Inferred** from TFID-shaped key + consumer W30-T). Reject scaffold `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_*`.
8. **Decompile ≡ bytes** for full leaf walk.  
   Full hex: raw W31-N append (59 B).

### Gaps

- Product map / value type at node `+0x20`.  
- One shared class vs layout clones across five callers.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cb4b0_StdMap_LowerBound_Tfid_Isnil29.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004cb4b0_StdMap_LowerBound_Tfid_Isnil29.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004cb4b0_FUN_004cb4b0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cb4b0_FUN_004cb4b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdMap_LowerBound_Tfid_Isnil29.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004cb4b0.cpp` |
| Function | `docs/reconstruction/functions/aa_004cb4b0_FUN_004cb4b0.md` |
| Function named | `docs/reconstruction/functions/aa_004cb4b0_StdMap_LowerBound_Tfid_Isnil29.md` |
| Scratch | `docs/reconstruction/tmp/a_004cb4b0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004bbeb0` | Port as **host reset** (not dtor): Recreate tableC hash via **pointer** `+0x18` with **log2=5**; drain three locked lists; `vector::resize(0)` on three embedded dword vectors; optional iface `vtbl[+4]` with **tail** on second flag. Preserve order. Do **not** swap CNDHash Free/Alloc twins from `004bcd40` family. |
| `004cb4b0` | Port as **pure lower_bound** for TFID-shaped keys; isnil **`+0x29`**; keys **`+0x10/+0x14`**. Callers must equality-gate before using `+0x20`. Do **not** substitute int-key / Val12 lower_bound helpers. Preserve **`RET 4`**. |
| Pair with | `CNDHash_Recreate_009cb450` (`0x004bcce0`, W30-G); `Object_TFIDMapLookupOrRelatedMatch` (`0x004c8970`, W30-T); find shell `FUN_004cba00`. |
| Closes | W30-G host residual for `004bbeb0`; W30-T nested `FUN_004cb4b0` not OWN. |

---

## Sibling context (not owned)

| VA | Role |
|---|---|
| `0x004bcce0` | CNDHash_Recreate_009cb450 (W30-G) — sole caller is this host reset |
| `0x004bc580` | locked-list drain under CS (scaffold present; not OWN here) |
| `0x00410420` | dword vector resize/clear helper |
| `0x004c8970` | Object TFID map lookup (W30-T) |
| `0x004cba00` / `0x004cc400` | find / insert-or-find shells over this lower_bound |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Rejected Server_needs_an_update / VOG_DEBUG_STOP scaffold aliases.
