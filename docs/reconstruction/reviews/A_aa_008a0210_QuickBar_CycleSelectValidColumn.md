# Review A (reconstruction fidelity): `aa_008a0210` QuickBar_CycleSelectValidColumn

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a0210` |
| **VA** | `0x008a0210` |
| **Body** | `0x008a0210`–`0x008a0368` exclusive (**344** B) |
| **Canonical name** | `QuickBar_CycleSelectValidColumn` |
| **Prior / alias** | `FUN_008a0210`; residual `Named_CalleeOf_Client_Input_PollBoundActions_008a0210` |
| **Review date** | `2026-07-29` (W21-T OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_008a0210_QuickBar_CycleSelectValidColumn.md` |
| **System** | client UI / quickbar |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_by_address`, xrefs / complete analysis / assembly context (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Cycle / bootstrap-select a filled quickbar column** on `CDlgQuickBar` host in **EBX**:

1. Find selected column among 10 slots at `host+0x63c` (`col+0x4fc != 0`).
2. Walk next (`direction != 0`) or prev (`direction == 0`) with wrap; accept only `+0x548 ∉ {0, 6}`.
3. On hit: `UI_QuickBarSlotButton_SetSelected(current,0)` then `SetSelected(target,1)`.
4. If no selection: first filled column gets inline select (RTTI + peer clear + highlight + `DAT_00d1da38` stamp + `+0x4fc=1`).
5. Always return AL=0; `ret 4`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_008a0210_FUN_008a0210.md` (+ W21-T append) |
| Annotated | `docs/reconstruction/raw/aa_008a0210_FUN_008a0210.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/QuickBar_CycleSelectValidColumn.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_008a0210.cpp` |
| Function record | `docs/reconstruction/functions/aa_008a0210_QuickBar_CycleSelectValidColumn.md` |
| Live decompile | ≡ raw (direction, 10-col walk, gates, bootstrap) |
| Live body bytes | `read_memory` @ `0x008a0210` length 360 |
| Sibling sealed | `aa_00826780` UI_QuickBarSlotButton_SetSelected |
| Parent context | `aa_008a0ed0` QuickBar_SelectPage_Inferred (calls with dir=1) |

---

## 3. Byte seal (`read_memory` @ `0x008a0210`)

```
55                push ebp
56                push esi
8d ab 3c 06 00 00 lea ebp, [ebx+0x63c]
57                push edi
33 ff             xor edi, edi          ; cur = 0
…
80 7c 24 10 00    cmp byte [esp+0x10], 0  ; direction stack arg
74 34             je  scan_prev
…                 ; next loop: wrap i>9 → 0; gate +0x548
…                 ; prev loop: wrap i<0 → 9
8b 8c bb 3c 06…  mov ecx, [ebx+edi*4+0x63c]  ; current
6a 00             push 0
e8 …              call SetSelected
8b 8c b3 3c 06…  mov ecx, [ebx+esi*4+0x63c]  ; target
6a 01             push 1
e8 …              call SetSelected
…
68 b4 e3 af 00    push CDlgQuickBar RTTI
68 90 e1 af 00    push gfxUIWindow RTTI
…
89 14 8d 38 da d1 00  mov [ecx*4+DAT_00d1da38], edx
c6 86 fc 04 00 00 01  mov byte [esi+0x4fc], 1
5f 5e 32 c0 5d c2 04 00  pop*; xor al,al; pop ebp; ret 4
```

| Claim | Evidence | Conf |
|---|---|---|
| Host column base +0x63c | `lea ebp,[ebx+0x63c]`; imm `3c 06 00 00` | **High** |
| 10-column loop | `cmp edi,0xa` / `jl` | **High** |
| Selected flag +0x4fc | `cmp byte [ecx+0x4fc],0` imm `fc 04` | **High** |
| Fill gate +0x548 ≠0,≠6 | `mov eax,[eax+0x548]`; `cmp 6` | **High** |
| Direction stack arg | `cmp [esp+0x10],0` after pushes | **High** |
| SetSelected pair different this | two `mov ecx,[ebx+reg*4+0x63c]` + push 0/1 | **High** |
| Bootstrap RTTI + DAT stamp | push `afe3b4`/`afe190`; store to `d1da38` | **High** |
| Always AL=0; ret 4 | final `32 c0 5d c2 04 00` both exits | **High** |
| Body 344 B | exclusive end `008a0368` | **High** |
| Decompile ≡ raw ≡ bytes intent | three-rep match (+ annotated ECX fix) | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Find selected among 10 | **Yes** |
| Dir 0 → prev / ≠0 → next with wrap | **Yes** |
| Fill gate before accept | **Yes** |
| Deselect current + select target | **Yes** (bytes; annotated/clean fix decompiler this gap) |
| Bootstrap when cur==10 | **Yes** |
| AL=0 / ret 4 / no invented net | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF algorithm | **High** | sealed three-rep |
| EBX host + stack direction ABI | **High** | all call sites load EBX host / push dir |
| Role = cycle filled column | **High** | matches SelectPage + PollBoundActions use |
| Product/PDB method English | **Low–Med** | structural name from role |
| Runtime / bit-exact | Open | static dual only |

**Verdict:** **accept** — cycle/bootstrap CF + ABI + layout sealed; product spelling residual.
