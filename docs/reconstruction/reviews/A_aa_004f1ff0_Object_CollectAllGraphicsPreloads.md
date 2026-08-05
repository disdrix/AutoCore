# Review A (reconstruction fidelity): `aa_004f1ff0` Object_CollectAllGraphicsPreloads

| Field | Value |
|---|---|
| **Stable ID** | `aa_004f1ff0` |
| **VA** | `0x004f1ff0`–`0x004f2531` (**1345 B**) |
| **Canonical name** | `Object_CollectAllGraphicsPreloads` (plate-backed) |
| **Ghidra name** | `FUN_004f1ff0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-H) |
| **Counterpart** | `reviews/B_aa_004f1ff0_Object_CollectAllGraphicsPreloads.md` |
| **System** | object graphics preload collection |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (prologue/epilogue + suffix strings) + callers/xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Profile-bracketed object graphics preload: build `stem (this+0x188) + suffix`, existence-gate, enqueue hits; type/`kind` select turret / fork / dual-tread packs; tail residual collectors + optional mission-media map walk.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W32-H append) | `docs/reconstruction/raw/aa_004f1ff0_FUN_004f1ff0.md` |
| Annotated | `docs/reconstruction/raw/aa_004f1ff0_FUN_004f1ff0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_CollectAllGraphicsPreloads.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004f1ff0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004f1ff0_Object_CollectAllGraphicsPreloads.md` |
| Related | `GameData_LookupCloneBaseByCbid` (`0x00404d70`); `GuardedVector_PushBack_Thiscall` (`0x0043d670`) |
| Live | decompile ≡ raw CF; `MOV EBP,ECX`; RET `C2 04 00`; 2 callers |

---

## 3. Signature (sealed)

```c
// ECX = object host; stack param_2; RET 0x4; void
void __thiscall Object_CollectAllGraphicsPreloads(void* self, uint32_t param_2);
```

| Slot | Source | Conf |
|---|---|---|
| self | **ECX** (`8B E9` = `MOV EBP,ECX`) | **High** |
| param_2 | Stack[+4]; forwarded to `FUN_004a04f0` | **High** |
| cleanup | `RET 0x4` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ live)

```
FUN_0076cf00("CollectAllGraphicsPreloads")
if (clonebase+0x3f2)&0x10: try stem+"_tint.dds"
if type==0x0e || (type==0x12 && clonebase+0x4e8==1): try stem+"_tur.geo"
if type!=0x0e: goto tail
clone = LookupCloneBaseByCbid(*(clonebase+0x6f4)); if !clone: goto tail
FUN_004f1e20(1,1)
kind = *( *(clone+0x3c) + 0x4ce )
  kind==2: _frkt.geo, _frkb.geo
  kind==4: _trdleft.geo, _trdleft_ai.anm, _trdright.geo, _trdright_ai.anm
FUN_004eb010()
tail:
FUN_004eb3b0()
if *(this+0x88): FUN_004a04f0(param_2, 1, 0, 0)
FUN_0076cef0()
```

Existence gate: `FUN_007b6a20(path,-1)` + `FUN_007b6730` → on true `00989e00` + `0043d670`.

| Stage | Match | Conf |
|---|---|---|
| Plate timer begin/end | **Yes** | **High** |
| Suffix constants (`read_memory`) | **Yes** | **High** |
| Type / kind gates | **Yes** | **High** |
| Clone lookup only for type 0x0e | **Yes** | **High** |
| Tail 004eb3b0 + optional 004a04f0 | **Yes** | **High** |
| Live ≡ raw CF | **Yes** | **High** |

---

## 5. Machine bytes (`read_memory`)

Entry: SEH; `sub esp,0x124`; **`MOV EBP,ECX`**; push plate string.  
Epilogue `0x004f2520`: restore FS; `add esp,0x130`; **`C2 04 00`**; pad `CC`.

Suffix strings sealed at `0x009cd004`–`0x009cd060` and `0x00a67574`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_004f2540` @ `0x004f25e6`; `FUN_004f26e0` @ `0x004f273e` |
| Links to OWN peer | via `FUN_004a04f0` → `MissionHost_CollectMediaPreloads_Inferred` |

---

## 7. Gaps

- Product English for type `0x0e`/`0x12` and kind `2`/`4`.  
- Nested `FUN_004eb010` / `FUN_004eb3b0` / `FUN_004f1e20` product roles (not OWN).  
- Preload vector ECX identity.  
- Runtime / bit-exact / differential.

---

## 8. Verdict

ABI, plate name, suffix set, type/kind CF, and tail walk sealed. Nested residual collectors product open → **accept-with-gaps**.
