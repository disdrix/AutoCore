# Review A (reconstruction fidelity): `aa_005755b0` VehicleCrew_InsertMember_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005755b0` |
| **VA** | `0x005755b0` |
| **Body** | `0x005755b0`–`0x00575694` exclusive (**228 B** / `0xE4`); pad `CC` |
| **Canonical name** | `VehicleCrew_InsertMember_Inferred` |
| **Ghidra symbol** | `FUN_005755b0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_005755b0_VehicleCrew_InsertMember_Inferred.md` |
| **System** | `skills-abilities` |
| **Agent** | WQ9D-D OWN-ONLY dual |
| **Live tools** | `decompile_function` / `batch_decompile`, `read_memory`, `analyze_function_complete`, xrefs (**no** `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** — CF/ABI/layout/callees sealed; zero callers + product English open |

---

## 1. Purpose

**Four-slot crew roster insert.** Writes a free `+0x198` slot (COID lo/hi + object*) when capacity and uniqueness allow; sets member back-link `+0xCB0`; appends COID to host vector `+0x1F4`; bumps u8 count `+0x1D8`.

```c
// __thiscall RET 4; AL bool
bool VehicleCrew_InsertMember_Inferred(CrewHost* this, void* member);
```

Twin reader: `VehicleCrew_ContainsMember_Inferred` (`0x005749d0`).

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_005755b0_FUN_005755b0.md` |
| Annotated | `docs/reconstruction/raw/aa_005755b0_FUN_005755b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleCrew_InsertMember_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_005755b0.cpp` |
| Twin Contains dual | `A|B_aa_005749d0_VehicleCrew_ContainsMember_Inferred.md` |
| Live decompile | ≡ raw CF |
| Body bytes | capacity gate; Contains call; free `(lo&hi)==~0`; success `B0 01` / fail `32 C0`; `RET 4` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body bounds 228 B | **Confirmed** | function meta + pad |
| `__thiscall` + `RET 4` + AL bool | **Confirmed** | epilogues |
| Capacity `(u8)+0x1D8 + (i32)+0x1E4 > 3` → 0 | **Confirmed** | decomp + `0fb686 d8010000` / `0386 e4010000` |
| Contains guard before write | **Confirmed** | call `FUN_005749d0` |
| Free sentinel both COID `0xFFFFFFFF` | **Confirmed** | `(lo & hi) == 0xFFFFFFFF` |
| 4 slots × stride `0x10` @ `+0x198` | **Confirmed** | loop `i < 4`; `puVar4 += 4` |
| object* @ `(i+0x1A)*0x10` | **Confirmed** | decomp + bytes |
| `FUN_00520330` → **member+0xCB0 = host** | **Confirmed** | call setup `ecx=member`, stack=host; setter body |
| `FUN_00418d70` this = **host+0x1F4** | **Confirmed** | `lea ecx,[esi+0x1F4]` |
| count++ @ `+0x1D8` | **Confirmed** | `80 86 d8 01 00 00 01` |
| VOG_DEBUG_STOP on no free slot | **Confirmed** | string push + `FUN_007a4480` |
| Direct CALL xrefs | **Confirmed empty** | gap (orphan) |
| Product C++ name | **Inferred** | structural + twin English |

---

## 4. Control flow

```
if count + bias > 3 → false
if Contains(member) → false
for i in 0..3:
  if free(slot[i]):
    write COID from member (offBase+0x164/168)
    store member*
    member+0xCB0 = host
    vector_push(host+0x1F4, COID)
    count++
    return true
VOG_DEBUG_STOP
return false
```

---

## 5. Gaps (acceptable)

1. Product English / MSVC demangle for crew-host class.  
2. **Zero** Ghidra CALL xrefs — who invokes insert in this image?  
3. Semantic English for `+0x1E4` bias and `+0x1F4` vector consumers.  
4. Slot dword `+0xC` unused residual.  
5. Runtime / bit-exact / differential (Terminal false).

**Verdict:** **accept-with-gaps** under `_Inferred` name.
