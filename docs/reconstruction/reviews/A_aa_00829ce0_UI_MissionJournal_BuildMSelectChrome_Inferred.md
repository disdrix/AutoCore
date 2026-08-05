# Review A (reconstruction fidelity): `aa_00829ce0` UI_MissionJournal_BuildMSelectChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00829ce0` |
| **VA** | `0x00829ce0`–`0x00829e80` exclusive |
| **Body size** | **416** B (`0x1A0`) |
| **Canonical name** | `UI_MissionJournal_BuildMSelectChrome_Inferred` |
| **Ghidra symbol** | `FUN_00829ce0` |
| **Review date** | `2026-07-29` (W26-R OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00829ce0_UI_MissionJournal_BuildMSelectChrome_Inferred.md` |
| **System** | client UI / mission journal |
| **Live tools** | Ghidra `decompile_function`, `analyze_function_complete`, `read_memory`, xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Build mission-journal **mselect** chrome widgets on panel `this`: mission button + status + title in mission mode, or category title only. Re-applies status complete label via sealed peer `FUN_00829ac0` using flag at `+0x4FD`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00829ce0_FUN_00829ce0.md` (+ W26-R append) |
| Annotated | `docs/reconstruction/raw/aa_00829ce0_FUN_00829ce0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_MissionJournal_BuildMSelectChrome_Inferred.cpp` |
| Scaffold | `reconstructed-exact/FUN_00829ce0.cpp` |
| Function record | `docs/reconstruction/functions/aa_00829ce0_UI_MissionJournal_BuildMSelectChrome_Inferred.md` |
| Live decompile | ≡ raw CF for widget build |
| Live body bytes | entry / branch / `00829ac0` handoff / epilogue via `read_memory` |
| Strings | four mselect XML paths @ `0x00a74944` / `0x00a7491c` / `0x00a748f4` / `0x00a748c8` |
| Peer duals | `A_aa_00829ac0_*`, `A_aa_00829b20_*`, `A_aa_008ae130_*` |

**Not performed:** `disassemble_bytes`, Launcher, runtime golden.

---

## 3. Byte seal (key sites)

### Prologue + mode branch

```
6a ff 68 0a 43 9b 00 ...     ; SEH LAB_009b430a
57 8b f9                     ; push edi; mov edi, ecx
e8 02 89 f6 ff               ; call FUN_00792600
80 bf fc 04 00 00 00         ; cmp byte [edi+0x4FC], 0
0f 85 09 01 00 00             ; jnz category arm
```

### Store / attach slots (mission arm samples)

```
89 87 04 05 00 00             ; [edi+0x504] = button
89 87 0c 05 00 00             ; [edi+0x50C] = status
89 87 08 05 00 00             ; [edi+0x508] = title
```

### Complete-label handoff

```
8a 87 fd 04 00 00             ; mov al, [edi+0x4FD]
8b f7                         ; mov esi, edi
e8 f6 fc ff ff                ; call FUN_00829ac0
```

### Epilogue

```
8b 4c 24 08 5f 64 89 0d 00 00 00 00 83 c4 10 c3
```

Exclusive end **`0x00829e80`** (next SEH prologue).

### Strings (`read_memory`)

| Addr | Content |
|---|---|
| `0x00a74944` | `i_d_npc_2d_btn_mselect_btn_mission.xml` |
| `0x00a7491c` | `i_d_npc_2d_btn_mselect_wnd_status.xml` |
| `0x00a748f4` | `i_d_npc_2d_btn_mselect_wnd_title.xml` |
| `0x00a748c8` | `i_d_npc_2d_btn_mselect_wnd_title_cat.xml` |

---

## 4. Fidelity checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw (widget CF) | **pass** |
| Body size 416 B exclusive end | **pass** |
| ECX → EDI thiscall | **pass** |
| Mode byte `+0x4FC` | **pass** |
| Button/status/title offsets | **pass** |
| Alloc sizes `0x4CC` / `0x488` | **pass** |
| AL from `+0x4FD` before `00829ac0` | **pass** (bytes; closes W25-G gap) |
| XML string identities | **pass** |
| Final refresh `vtbl+0x34C` | **pass** |
| SEH teardown vs decompile noise | **bytes win** |
| Product plate spelling | **gap** |
| `vtbl+0x74(60000)` meaning | **gap** |
| Runtime / differential | **gap** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Role = mselect chrome builder | **High** | XML + peer journal duals |
| Mission vs category branch | **High** | `cmp [+0x4FC]` |
| Widget slot map | **High** | stores + peer status dual |
| Construct AL intent | **High** | explicit load of `+0x4FD` |
| Indirect-only callers | **High** | DATA `0x00a748c0` |
| Product C++ name | **Inferred** | |

---

## 6. Gaps

1. Product English / exact method plate.  
2. Semantics of button `vtbl+0x74(60000)`.  
3. Full dual of `FUN_00792600` / button ctor / window ctor (not OWN).  
4. Who sets `+0x4FC` category mode before call.  
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
