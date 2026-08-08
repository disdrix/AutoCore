# Review B (skeptical / adversarial): `aa_00402280` StdList_Destroy_FreeHead_ViaClearEsi_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402280` |
| **VA** | `0x00402280` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (MEGA-067 OWN dual) |
| **Counterpart** | `reviews/A_aa_00402280_StdList_Destroy_FreeHead_ViaClearEsi_Inferred.md` |
| **System** | shared `client::stdlist` |
| **Verdict** | **accept-with-gaps** |

**Tools:** same live Ghidra set as A. **No** `disassemble_bytes`. No Launcher. No runtime Confirmed.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `operator_delete` never returns; body ends at delete | Ghidra WARNING only; bytes continue `ADD ESP,4; MOV [ESI+4],0; POP ESI; RET` | **Falsified** as CF |
| 2 | Mission_createNDUIDialogs-specific helper | 10 unwind sites + UI dtor/ctor vector; no mission strings; CF = stdlist destroy | **Falsified** |
| 3 | Named_CalleeOf scaffold is correct product name | Parent-seed auto chain; twin family already named Destroy_FreeHead | **Falsified** — retired |
| 4 | ECX is tree/map node, not list shell | Clear leaf `00415e90` is dualed list clear (head@+4, size@+8); eh_vector size 0xC | **Falsified** |
| 5 | Frees entire list object (shell) | Only free sentinel; shell is stack/embed/array element | **Falsified** |
| 6 | thiscall `RET 4` / stack arg | bare `C3`; no stack formals | **Falsified** |
| 7 | Same VA as `00403430` | Distinct CALL target (15e90 vs 04060); same outer pattern only | **Falsified** as merge |
| 8 | Clear leaf already frees sentinel | Dualed clear keeps head; this unit frees head after | **Survives** two-step dtor |
| 9 | Returns useful EAX | Callers are unwind/vector dtors; no post-return EAX use | **Survives** void |
| 10 | Product `list<T>` English sealed | No RTTI demangle on this leaf | **Survives as gap** → `_Inferred` |

---

## 2. Live ≡ raw ≡ bytes

Decompiler:

```c
void __fastcall FUN_00402280(int param_1)
{
  FUN_00415e90();
  operator_delete(*(void **)(param_1 + 4));
}
```

`read_memory` restores full CF (null head + epilogue). Annotated/clean include restored tail. **Match** on sealed stages.

---

## 3. ABI adversarial check

| Probe | Observation |
|---|---|
| Unwind sites | `LEA ECX,[EBP+local]; JMP 00402280` — thiscall local shell |
| eh_vector | dtor VA `0x402280`, elem **0xC**, count **4** @ host+0x5cc |
| Ctor pair | `FUN_004023f0` buys empty sentinel — classic list shell life cycle |
| Clear twin path | `00403430` identical outer bytes with different clear CALL |

---

## 4. Surviving contract

```text
// ECX = list shell*
// 1) StdList_Clear_ESI (ESI path)
// 2) operator_delete(head@+4)
// 3) head = 0
// bare RET; void
```

**Gaps kept:** product `list<T>` English; host class plate for `008a5ba0`/`008a5c90`; runtime / bit-exact / differential.

**Not gaps:** control flow, thiscall ABI, clear+free-head semantics, scaffold retirement.

---

## 5. Verdict

Path B does **not** force reject. Mission identity and noreturn-truncation claims fail hard. Residual product-English / host-class / runtime → **accept-with-gaps** (aligned with twin `00403430` and clear leaf `00415e90`).

**Verdict:** **accept-with-gaps**.
