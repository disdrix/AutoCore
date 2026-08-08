# Review A (reconstruction fidelity): `aa_00402280` StdList_Destroy_FreeHead_ViaClearEsi_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00402280` |
| **VA** | `0x00402280` |
| **Body** | `0x00402280`–`0x0040229c` inclusive (**29** B / `0x1D`) |
| **Canonical name** | `StdList_Destroy_FreeHead_ViaClearEsi_Inferred` |
| **Ghidra name** | `FUN_00402280` |
| **Review date** | `2026-08-05` (MEGA-067 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00402280_StdList_Destroy_FreeHead_ViaClearEsi_Inferred.md` |
| **System** | shared `client::stdlist` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC circular **`std::list` shell complete destructor**: convert thiscall **ECX→ESI**, call dualed **`StdList_Clear_ESI`**, `operator_delete` the sentinel at `list+4`, null `list+4`. Shell object itself is not freed.

```text
// ECX = list shell*  (+4 head, +8 size)
StdList_Clear_ESI(list);          // FUN_00415e90 via ESI
operator_delete(*(void**)(list+4));
*(void**)(list+4) = 0;
// bare RET
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-067 re-verify) | `docs/reconstruction/raw/aa_00402280_FUN_00402280.md` |
| Annotated | `docs/reconstruction/raw/aa_00402280_FUN_00402280.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdList_Destroy_FreeHead_ViaClearEsi_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00402280.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Mission_createNDUI_00402280.cpp` |
| Function records | `functions/aa_00402280_FUN_00402280.md`, `functions/aa_00402280_StdList_Destroy_FreeHead_ViaClearEsi_Inferred.md` |
| Live body | `read_memory` 29 B + pad |
| Clear leaf | dual `StdList_Clear_ESI` @ `0x00415e90` |
| Twin destroy | dual `StdList_Destroy_FreeHead_Inferred` @ `0x00403430` |

---

## 3. Calling convention (assembly-sealed)

| Slot | Role | Evidence |
|---|---|---|
| ECX | list shell* | entry `MOV ESI,ECX`; unwind `LEA ECX,[EBP+…]`; eh_vector dtor |
| ESI | working list* | prologue save; clear leaf ABI |
| stack formals | none | bare `RET` (`C3`) |
| cleanup | bare **`RET`** | no `RET n` |
| return | void | no EAX product |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body span 29 B + `CC` pad | **Confirmed** | `read_memory` hex ends `5E C3 CC` |
| ECX thiscall → ESI | **Confirmed** | `56 8B F1` |
| Clear via `00415e90` | **Confirmed** | relative CALL seals target |
| Free sentinel @ +4 then null | **Confirmed** | bytes after delete: `C7 46 04 00…` |
| Decompiler truncates after delete | **Confirmed** | false noreturn; null+epilogue live |
| Shell size 0xC at vector sites | **Confirmed** | `_eh_vector_*_iterator_(…, 0xC, 4, 00402280)` |
| Element product type T | **Open** | site-dependent; clear only deletes nodes |
| Host class English (`00a4c61c`) | **Open** | out of OWN; evidence only |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 5. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| PUSH ESI; ESI=ECX | **Yes** |
| CALL StdList_Clear_ESI | **Yes** |
| PUSH [ESI+4]; operator_delete; ADD ESP,4 | **Yes** |
| [ESI+4]=0 | **Yes** (bytes; decomp missing) |
| POP ESI; RET | **Yes** |
| No free(list shell) | **Yes** |

---

## 6. Naming gate

- Role = list destroy (clear + free head + null) sealed against dualed clear leaf and twin destroy `00403430`.
- Qualifier **ViaClearEsi** distinguishes this VA from Clear-ECX twin `00403430`.
- Product demangle of `list<T>` open → **`_Inferred`**.
- Retired mission Named_CalleeOf scaffold (shared util, multi-site).

**Verdict:** **accept-with-gaps**.
