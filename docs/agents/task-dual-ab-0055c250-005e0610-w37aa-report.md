# Dual A/B report — W37-AA OWN `aa_0055c250` + `aa_005e0610`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual W37-AA  
**Scope:** VAs `0x0055c250`, `0x005e0610` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / parent ledgers.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` + callers/callees/xrefs + callee context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wave37_partition_map.md` (W37-AA).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0055c250` StdVector_Resize_Elem28 | **accept-with-gaps** — thiscall resize RET 0x20, stride 0x1c, grow InsertN + shrink end rebind sealed; product Elem28 English open |
| `aa_005e0610` LootCatalog_TallyObjectAndEnqueueNotify_Inferred | **accept-with-gaps** — tally/notify CF + bytes corrections (bucket M, counters, path bases) sealed; product bank/grid English open |

**Terminal coverage:** false (both).

---

## VA `0x0055c250` — sealed facts

1. **Body:** `0x0055c250`–`0x0055c306` exclusive (**182 B** / `0xB6`; pad `CC` before `FUN_0055c310`).
2. **ABI:** **`__thiscall`**; ECX = `vector*`; stack **`uint32 new_size` + `Elem28` by value (0x1c)**; void; dual epilogues **`C2 20 00`** (`ret 0x20`). Decompiler signature omits the value blob.
3. **Layout:** begin@`+4`, end@`+8`, capEnd@`+0xC` (unused here). Stride **0x1c**. Size via magic **`0x92492493`**; begin==0 → size 0.
4. **Semantics:**
   - If `new_size <= size`: optional shrink when `new_size < size` — `new_end = begin + new_size*0x1c`; `FUN_0055b470(end, end, new_end)` (cdecl; 4th push unused); **`[end] = EAX`**. Helper entry loads dest into EAX; empty range returns dest.
   - If `new_size > size`: `StdVector_InsertN_Elem28(end, new_size-size, &value)` @ `0x0055c2ae` (W34-R sealed).
5. **Classification:** worker (generic vector resize, POD T).
6. **Callers (1):** `FUN_0055a5f0` @ `0x0055a684` (clone/copy host vector to matching size).
7. **Callees:** `FUN_0055be00` / `StdVector_InsertN_Elem28`, `FUN_0055b470`.
8. **Name:** `StdVector_Resize_Elem28` (Ghidra `FUN_0055c250`). **Reject** scaffold `Named_CalleeOf_*VOG_DEBUG*`. Peer resize `StdVector_Resize_Pod28` (`0x0045c4b0`) is **different register ABI** (EBX/ECX, RET 0x1C) — do not merge.
9. **Decompile ≡ CF skeleton**; bytes seal full stack ABI and shrink return.  
   Full hex: `5556578bf98b770485f6750433c0eb188b4f082bceb893244992f7e903d1c1fa048bc2c1e81f03c28b6c24103bc5733985f6750433c0eb188b4f082bceb893244992f7e903d1c1fa048bc2c1e81f03c28b4f088d542414522be855518bcfe84dfbffff5f5e5dc2200085f67443538b5f088bcb2bceb893244992f7e903d1c1fa048bc2c1e81f03c23be873238d04ed000000002bc58d04863bc374138b4c241451505353e877f1ffff83c4108947085b5f5e5dc22000`

### Gaps

- Product English for host `Elem28`.  
- Unowned shrink helper / parent cloner duals.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0055c250_StdVector_Resize_Elem28.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0055c250_StdVector_Resize_Elem28.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0055c250_FUN_0055c250.md` |
| Annotated | `docs/reconstruction/raw/aa_0055c250_FUN_0055c250.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_Resize_Elem28.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055c250.cpp` |
| Function | `docs/reconstruction/functions/aa_0055c250_FUN_0055c250.md` |
| Function named | `docs/reconstruction/functions/aa_0055c250_StdVector_Resize_Elem28.md` |

---

## VA `0x005e0610` — sealed facts

1. **Body:** `0x005e0610`–`0x005e07c5` exclusive (**437 B** / `0x1B5`; pad `CC`).
2. **ABI:** **`__thiscall`**; ECX = large **manager***; stack **`object*`, `bandIndex`, `notifyPath`**; void; dual exits **`C2 0C 00`** (`ret 0x0C`).
3. **Object fields used:** id@`+0x34`, type@`+0x38`, clonebase*@`+0x3c`. Clonebase: kind short@`+0x3f4`, race short@`+0x4b8`, flags@`+0x535`/`+0x536`, vtable vfunc@`+0x14`.
4. **Semantics (bytes authority where decompile wrong):**
   - Call clonebase vfunc `+0x14` → `vfuncRet`; stash object id; `MOVSX` race short (flags from `TEST` preserved across).
   - If clonebase null: `FUN_004f1e20(0,1)` then reload; if still null return.
   - Type remap: kind `0xB`→ type **0x46**, kind `0xA`→ **0x44**, else object type; type **0xC** may Val12 insert-or-find on **manager** via `FUN_00418b80` + `FUN_005e18d0` (W30-L) when owner key matches `manager+4` and flag gates.
   - Gate: skip catalog path if **`(vfuncRet == -1 && type == 0xE)`**.
   - **M** = map `vfuncRet`: 0→0, 1→1, 2→2, else→3 (**decomp miss**).
   - **R** = `LootCatalog_TypeCodeToRowIndex_Inferred(type)` (`FUN_005e0480`); if R < 0 skip.
   - **P** = `(bandIndex > 0) ? bandIndex-1 : 0`; **S** = race short.
   - Counters (EBX=1): `++mgr[0x13ce0c+M*4]`, `++mgr[0x13ce1c+P*4]`, `++mgr[0x13cf5c+R*4]`, `++mgr[0x13cf8c+S*4]`. First index is **M**, not high half of row (**decomp wrong**).
   - If `notifyPath` is 0 or 1:  
     `t = 0x50*(R + 12*M) + P`, `u = 16*(S + 9*t)`,  
     `CVOGReaction_FailMissionNotify(mgr + u + (path==1 ? 0xC : 0x8700C), &objectId)`  
     (callee = dword vector push; path bases **differ** — decomp shows identical).
5. **Classification:** worker (loot catalog tally + optional id enqueue).
6. **Callers (1 fn / 3 sites):** `FUN_00541e70` @ `00542341`, `0054236d`, `0054239c` (CloneBase load; paired with unowned `FUN_005e0580`).
7. **Callees:** vfunc+0x14, `FUN_004f1e20`, `FUN_00418b80`, `FUN_005e18d0`, `FUN_005e0480`, `CVOGReaction_FailMissionNotify`.
8. **Name:** `LootCatalog_TallyObjectAndEnqueueNotify_Inferred` (Ghidra `FUN_005e0610`; **Inferred**). **Reject** scaffold Mission_after_CVOGRegionMissions plate.
9. **Decompile ≡ skeleton**; bytes correct M map, counters, notify `this`.  
   Full hex: `83ec1c535556578b7c24308bf18b4f3c8b01ff50148b4f388b5f34894424148b473c85c00fbfa8b8040000894c2430895c2410750a6a01508bcfe8d117f1ff8b7f3c85ff0f8461010000668b87f4030000663d0b00750ac744243046000000eb6f663d0a00750ac744243044000000eb5f837c24300c75588d542410528d44241c508bcee8e784e3ff8b083b4e0475408a8736050000a80475368a8f3505000084c9742cd0e80fb6c924018844241c8b54241c894c24248d442420508d4c241c518bce895c242889542430e8f01100008b44241483f8ff750b837c24300e0f84c700000083e800bb01000000741a2bc374122bc37407ba03000000eb0dba02000000eb068bd3eb0233d28b442430508bcee85afdffff85c00f8c8d0000008b7c243433c985ff7e038d4fff019c960cce1300019c8e1cce1300019c865ccf13008b7c2438019cae8ccf130083ef0074332bfb75578d14528d04908d0480c1e00403c18d4cc50003c8c1e1048d7c24108d4c310c57e84742e3ff5f5e5d5b83c41cc20c008d14528d04908d0480c1e00403c18d4cc50003c8c1e1048d7c24108d8c310c70080057e81542e3ff5f5e5d5b83c41cc20c00`

### Gaps

- Product English for counter banks / reaction grid / manager type.  
- Val12 value field packing beyond key=objectId.  
- Clonebase vfunc `+0x14` product name.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005e0610_LootCatalog_TallyObjectAndEnqueueNotify_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_005e0610_LootCatalog_TallyObjectAndEnqueueNotify_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005e0610_FUN_005e0610.md` |
| Annotated | `docs/reconstruction/raw/aa_005e0610_FUN_005e0610.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/LootCatalog_TallyObjectAndEnqueueNotify_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005e0610.cpp` |
| Function | `docs/reconstruction/functions/aa_005e0610_FUN_005e0610.md` |
| Function named | `docs/reconstruction/functions/aa_005e0610_LootCatalog_TallyObjectAndEnqueueNotify_Inferred.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0055c250` | Port as **`vector<Elem28>::resize(n, value)`**: thiscall + **RET 0x20** (size + 0x1c value). Grow → W34-R InsertN at end. Shrink → end rebind only (POD, no dtor). **Do not** reuse `0045c4b0` register ABI. |
| `005e0610` | Port as **CloneBase-load loot tally**: manager thiscall; `(obj, band, path)`; type overrides; row via `005e0480`; four counters keyed by **M/P/R/S**; notify only for path 0/1 with **distinct** vector bases (`+0x8700C` vs `+0xC`) after shared index formula. **Ignore** decompiler high-half counter and identical-notify-this. |
| Shared | No shared type surface between these two VAs (vector POD vs loot manager). Both reject scaffold Named_CalleeOf plates. Avoid bare `undefined4` in clean (`uint32_t` / structs). |

### Related (not owned)

| VA | Role |
|----|------|
| `0x0055be00` | InsertN grow callee (W34-R) |
| `0x0055b470` | Shrink POD range helper |
| `0x0055a5f0` | Sole resize caller |
| `0x0055c310` | Sibling insert-one wrapper |
| `0x005e0480` | Type→row (W16-C) |
| `0x005e18d0` | Val12 insert-or-find (W30-L) |
| `0x00541e70` | CloneBase load parent |
| `0x004149d0` | `CVOGReaction_FailMissionNotify` (dword vector push) |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers + callee/caller context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** (W37-AA sections).  
- No invented product plates; structural `StdVector_*` / loot `_Inferred` names from sealed CF + related duals.  
- Rejected scaffold VOG_DEBUG / Mission Named_CalleeOf product roles.  
- Avoided bare `undefined4` in clean (`uint32_t` / structs / opaque manager types).
