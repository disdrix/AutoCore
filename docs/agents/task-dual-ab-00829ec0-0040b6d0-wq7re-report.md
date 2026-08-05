# Dual A/B report — WQ7R-E OWN `aa_00829ec0` + `aa_0040b6d0`

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual WQ7R-E  
**Scope:** VAs `0x00829ec0`, `0x0040b6d0` only. Dual A/B + trio artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `batch_decompile` / `decompile_function` + `read_memory` + callers/xrefs + `get_assembly_context` + parent/callee cross-checks. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq007_residual_partition_map.md` (WQ7R-E — Journal/UI + vector helper).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00829ec0` UI_MissionJournal_MSelectEntry_Ctor_Inferred | **accept-with-gaps** — journal mselect entry ctor; size `0x510`; XML + tail fields sealed |
| `aa_0040b6d0` StdVector_InsertOne_RebindIt_Via419880_Inferred | **accept** — dword insert-one + rebind; EDI/EBX; count=1 via `00419880` |

---

## VA `0x00829ec0` — sealed facts

1. **Body:** `0x00829ec0`–`0x00829f3b` (**123 B** / `0x7B`); pad `CC` after `ret 4`.
2. **ABI:** stack **`this`**; returns **`this`** in EAX; **`ret 4`** (`C2 04 00`). Not pure ECX-thiscall.
3. **Semantics:** Mission-journal **mselect entry** widget ctor:
   - Base: `FUN_00792d20` = `NDUIContainerPanel_Ctor_Inferred`
   - Vtbl: `PTR_FUN_00a74484`
   - Clear `+0x4FC` (category), `+0x4FD` (complete flag)
   - `+0x500 = 0xFFFFFFFF` selection/key sentinel
   - Null children `+0x504` / `+0x508` / `+0x50C`
   - `NDUIWindow_ReloadInterface("i_d_npc_2d_btn_mselect.xml")` (string @ `0x00a74978`)
4. **Alloc size:** callers always `operator_new(0x510)`.
5. **Callers:** sole function `Client_UpdateMissionJournal` (`0x008ae130`) — 4 sites (`008ae38f`, `008ae47d`, `008ae557`, `008ae666`); control ids base **`0x9c4f`**.
6. **Peers:** `UI_MissionJournal_BuildMSelectChrome_Inferred` (`0x00829ce0`) consumes same tail offsets.
7. **Name:** `UI_MissionJournal_MSelectEntry_Ctor_Inferred` (Ghidra `FUN_00829ec0`; string + journal path). **Reject** mission-logic naming.
8. **Decompile ≡ bytes** for CF; field order `+0x4FD` then `+0x4FC` sealed by stores.

### Gaps

- Product C++ class / PDB symbol.  
- Full vtbl map for `00a74484`.  
- Later writers of `+0x500` (bind path).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00829ec0_UI_MissionJournal_MSelectEntry_Ctor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00829ec0_UI_MissionJournal_MSelectEntry_Ctor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00829ec0_FUN_00829ec0.md` |
| Annotated | `docs/reconstruction/raw/aa_00829ec0_FUN_00829ec0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionJournal_MSelectEntry_Ctor_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_00829ec0.cpp` |
| Function | `docs/reconstruction/functions/aa_00829ec0_FUN_00829ec0.md` |
| Function named | `docs/reconstruction/functions/aa_00829ec0_UI_MissionJournal_MSelectEntry_Ctor_Inferred.md` |

---

## VA `0x0040b6d0` — sealed facts

1. **Body:** `0x0040b6d0`–`0x0040b713` (**68 B** / `0x44`); pad `CC` after `ret 8`.
2. **ABI:** **customcc** — **EDI** = vector host (`begin@+4`/`end@+8`/`capEnd@+0xC`); **EBX** = out-iterator holder (`T**`); stack **`(where*, value*)`**; **`ret 8`**; **EAX = EBX**.
3. **Semantics:** MSVC-style **`vector<uint32_t>` insert-one + rebind iterator**:
   - `index = empty ? 0 : (where - begin) >> 2`
   - Call `StdVector_InsertN_Dword_CountEcx_Inferred` (`0x00419880`) with **ECX = 1**
   - `*outIt = begin' + index * 4` (valid after realloc)
4. **Callee:** sealed W23-D CountEcx insert-N engine (1.5× growth / throw policy owned there).
5. **Caller:** sole listed `FUN_00411180` @ `0x004111c1` — push_back slow path when `size >= capacity`; fast path `*end++ = *value`.
6. **Twins:** `0040dbf0` (thiscall/`004073a0`); `00466da0` (same EDI/EBX shape / different engine `00456960`).
7. **Name:** `StdVector_InsertOne_RebindIt_Via419880_Inferred` (Ghidra `FUN_0040b6d0`; **Inferred**). **Reject** scaffold `Named_CalleeOf_…MissionJournal…` as product domain name.
8. **Decompile CF spine OK**; register ABI sealed by bytes + parent (decompiler `unaff_*` noise).

### Gaps

- Product / MSVC demangle.  
- Runtime / bit-exact / differential.  
- Future xrefs beyond `FUN_00411180` (none today).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040b6d0_StdVector_InsertOne_RebindIt_Via419880_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0040b6d0_StdVector_InsertOne_RebindIt_Via419880_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040b6d0_FUN_0040b6d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040b6d0_FUN_0040b6d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_InsertOne_RebindIt_Via419880_Inferred.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0040b6d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040b6d0_FUN_0040b6d0.md` |
| Function named | `docs/reconstruction/functions/aa_0040b6d0_StdVector_InsertOne_RebindIt_Via419880_Inferred.md` |

---

## AutoCore impact

| VA | Port guidance |
|----|----------------|
| `00829ec0` | Port as **mission-journal mselect entry ctor** (`sizeof=0x510`). Base container panel + skin `i_d_npc_2d_btn_mselect.xml`. Init tail: category/complete bytes 0, selection −1, null chrome children. Used only when rebuilding Active/New lists in journal dialog state 3. |
| `0040b6d0` | Port as **`vector<uint32_t>::insert` one-element rebind helper**: EDI=vector, EBX=out iterator, stack where/value, **ret 8**, engine = CountEcx insert-N (`00419880`) with count 1. Pair with push_back parent `FUN_00411180` (capacity-full branch). **Not** mission logic. |
| Shared | Unrelated domains (journal UI ctor vs generic dword vector). Co-owned only by WQ7R-E partition pair. |

---

## Cross-links (not owned)

| VA | Role | Owner hint |
|----|------|------------|
| `0x008ae130` | `Client_UpdateMissionJournal` (sole ctor caller) | already dualed |
| `0x00829ce0` | `UI_MissionJournal_BuildMSelectChrome_Inferred` | already dualed |
| `0x00792d20` | `NDUIContainerPanel_Ctor_Inferred` | already dualed |
| `0x00419880` | `StdVector_InsertN_Dword_CountEcx_Inferred` | W23-D sealed |
| `0x00411180` | push_back parent of insert-one | WQ7R-D residual set |

---

## Summary

Closes WQ7R-E OWN pair: journal/UI mselect **entry ctor** (`00829ec0`) + dword vector **insert-one rebind** helper (`0040b6d0` via CountEcx engine). No parent ledger edits. No Launcher. No `disassemble_bytes`.
