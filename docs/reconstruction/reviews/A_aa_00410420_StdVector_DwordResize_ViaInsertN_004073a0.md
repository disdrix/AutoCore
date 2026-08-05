# Review A (reconstruction fidelity): `aa_00410420` StdVector_DwordResize_ViaInsertN_004073a0

| Field | Value |
|---|---|
| **Stable ID** | `aa_00410420` |
| **VA** | `0x00410420` |
| **Body** | `0x00410420`–`0x00410488` inclusive (**105 B** / `0x69`); pad `CC` then `FUN_00410490` |
| **Canonical name** | `StdVector_DwordResize_ViaInsertN_004073a0` (**Inferred**); Ghidra `FUN_00410420` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00410420_StdVector_DwordResize_ViaInsertN_004073a0.md` |
| **System** | STL / container utility (multi-domain dword vectors) |
| **Live tools** | Ghidra `batch_decompile`, `analyze_function_complete`, `read_memory`, xrefs, `get_assembly_context` (no `disassemble_bytes`) |
| **Verdict** | **accept** — CF/ABI/`ret 8`/grow+shrink wiring sealed; product STL symbol open |
| **Dual status** | **Present (W37-T)** |

---

## 1. Purpose

**Resize** a MSVC-style `vector<uint32_t>`-shaped object. Control block consumed here:

| Offset | Role |
|---|---|
| `vec+0x04` | begin (`T*`) |
| `vec+0x08` | end (`T*`) |
| `vec+0x0C` | capacity end (grow callee only) |

```
size = (begin == 0) ? 0 : (end - begin) >> 2;

if (size < newCount):
  FUN_004073a0(this, end, newCount - size, &fillValue);  // insert-N at end
  return;

if (begin != 0 && newCount < size):
  FUN_00410490(this, &tmp, begin + newCount*4, end);    // erase range
return;  // equal → no-op
```

**ABI:** `__thiscall`; stack `(newCount, fillValue)`; **`ret 8`**.

Near-clone of sealed role twin `StdVector_DwordResize` (`FUN_004367f0`): same size math and shrink path; **different grow insert-N** (`004073a0` here vs `004507a0` there).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Fresh decompile | Ghidra `batch_decompile` `0x00410420` (2026-08-04) — **≡ raw** |
| Complete analysis | 30 xrefs; callees `FUN_004073a0`, `FUN_00410490`; 21 callers |
| Machine | `read_memory` `0x00410420` length 128 → body **105 B** then `CC` |
| Grow callee | `FUN_004073a0` (insert-N dword family) |
| Shrink callee | `FUN_00410490` — dual sealed `StdVector_EraseRange_Dword_Inferred` (W16-S) |
| Twin resize | `A_aa_004367f0_StdVector_DwordResize` (grow via `004507a0`) |
| Caller sites | e.g. `004bbeb0` `push 0; push 0; lea ecx,[esi+off]; call` |
| Scaffold | `raw/aa_00410420_*`, `reconstructed-exact/FUN_00410420.cpp` |

**Not performed:** Launcher, runtime golden, bit-exact image diff, parent ledger edits.

---

## 3. Machine seal (`read_memory`)

| Claim | Evidence | Conf |
|---|---|---|
| begin `this+4`, end `this+8` | `8b 51 04` / `8b 41 08` | **Confirmed** |
| size `>> 2` (dword) | `c1 f8 02` | **Confirmed** |
| newCount from stack after `push esi` | `8b 74 24 08` | **Confirmed** |
| Grow: `call FUN_004073a0` then **`ret 8`** | `e8 42 6f ff ff` … `c2 08 00` | **Confirmed** |
| Grow passes `&fill` | `8d 7c 24 10; 57` before call | **Confirmed** |
| Shrink: `lea eax,[edx+esi*4]` + `call FUN_00410490` + **`ret 8`** | `8d 04 b2` / `e8 0c 00 00 00` / `c2 08 00` | **Confirmed** |
| Body length 105 B | last `c2 08 00` @ `0x00410486`; next `CC` then `00410490` | **Confirmed** |
| Equal size no-op | fall-through to `ret 8` without call | **Confirmed** |

Full hex (105 B):

```
8b510485d2750433c0eb088b41082bc2c1f802568b7424083bc657732685d2750433c0eb088b41082bc2c1f8028b51088d7c2410572bf05652e8426fffff5f5ec2080085d2741d8b79088bc72bc2c1f8023bf0730f8d04b257508d44241450e80c0000005f5ec20800
```

---

## 4. Callers / callees

| Direction | Detail |
|---|---|
| Callees | `FUN_004073a0` grow; `FUN_00410490` shrink |
| Callers | 21 functions / 30 sites — multi-domain clears and resizes (see `analyze_function_complete`) |
| Typical clear | `push 0; push 0; lea ecx, vec; call` → resize(0, fill0) |

---

## 5. Confidence table

| Claim | Level |
|---|---|
| Control flow ≡ live | **Confirmed** |
| Element width dword | **Confirmed** |
| `__thiscall` + `ret 8` | **Confirmed** |
| Role = dword vector resize | **Confirmed** |
| Grow engine = `004073a0` (not `004507a0`) | **Confirmed** |
| POD-only shrink (no element dtors here) | **Confirmed** (via `00410490`) |
| Product / PDB name | **Open** |

---

## 6. Gaps

1. Product STL demangle.  
2. Rationale for two resize clones with different insert-N engines.  
3. Runtime / differential.

**Verdict:** **accept**
