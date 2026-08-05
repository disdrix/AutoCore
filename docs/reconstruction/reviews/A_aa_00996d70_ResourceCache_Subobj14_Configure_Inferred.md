# Review A (reconstruction fidelity): `aa_00996d70` ResourceCache_Subobj14_Configure_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00996d70` |
| **VA** | `0x00996d70`–`0x00996dbb` (**76 B**) |
| **Canonical name** | `ResourceCache_Subobj14_Configure_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00996d70` |
| **Review date** | `2026-08-04` (W37-V dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-V) |
| **Counterpart** | `reviews/B_aa_00996d70_ResourceCache_Subobj14_Configure_Inferred.md` |
| **System** | ResourceCache / embedded configure subobject |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (full 76 B) + `analyze_function_complete` + caller/callee decompile + `00989b00` bytes |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Reconfigure the ResourceCache embedded subobject (typically host `+0x14`): clear nested list, reset vector shell with arg **9**, set counters `+0x48`/`+0x4C` to **1**, free aligned buffer state, store stack **flag** at `+0x50`, realloc buffer with **align 4** and size from **EBX**.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00996d70_FUN_00996d70.md` (+ W37-V append) |
| Annotated | `docs/reconstruction/raw/aa_00996d70_FUN_00996d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ResourceCache_Subobj14_Configure_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00996d70.cpp` |
| Function | `docs/reconstruction/functions/aa_00996d70_FUN_00996d70.md` |
| Named | `docs/reconstruction/functions/aa_00996d70_ResourceCache_Subobj14_Configure_Inferred.md` |
| Live | decompile CF + full 76 B hex; 2 callers; 4 callees |
| Context | W31-F `ResourceCache_SetField10AndConfigure`; `00989b00` buffer helper bytes |

---

## 3. Signature (sealed)

```c
// EAX=subobj; EBX=size; stack flag; RET 4; void
void ResourceCache_Subobj14_Configure_Inferred(
    void *subobj /*EAX*/,
    uint32_t size /*EBX*/,
    uint8_t flag /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| subobj | `MOV EDI,EAX` | **High** |
| size | live **EBX** into `00989b00` (`TEST EBX`; store `+0x14`) | **High** |
| flag | `MOV CL,[esp+0x10]` → `+0x50`; `RET 4` | **High** |
| align | `MOV EAX,4` before `00989b00` | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
EDI = EAX (subobj)
ESI = EDI+0x2C; FUN_00415e90()          // clear list
scratch = *(EDI+0x30)
PUSH 9; ECX = EDI+0x38; FUN_00449a90()
*(EDI+0x48)=1; *(EDI+0x4C)=1
FUN_009899a0()                          // EDI free buffers
*(EDI+0x50) = stack_flag
PUSH 1; EAX=4; ECX=EDI; FUN_00989b00()  // EBX=size
RET 4
```

| Stage | Match | Conf |
|---|---|---|
| EAX→EDI subobj | **Yes** | **High** |
| List clear @+0x2C | **Yes** | **High** |
| Vector @+0x38 arg 9 | **Yes** | **High** |
| Counters +0x48/+0x4C | **Yes** | **High** |
| Flag +0x50 | **Yes** | **High** |
| Buffer free/realloc align 4 | **Yes** | **High** |
| EBX size formal | **Yes** (callee + callers) | **High** |
| Product field English | open | **Low** |

---

## 5. Gaps / open

1. Product English for subobject class and fields `+0x48`/`+0x4C`/`+0x50`.
2. Full dual of unowned callees (`00415e90`, `00449a90`, `009899a0`, `00989b00`).
3. Why `00989d50` pre-clears overlapping state then re-enters (redundant retail).
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** — ABI/CF/offsets/parent family sealed; product English + full callee contracts open.
