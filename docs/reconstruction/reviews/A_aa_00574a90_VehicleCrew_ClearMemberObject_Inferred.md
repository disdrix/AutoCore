# Review A (reconstruction fidelity): `aa_00574a90` VehicleCrew_ClearMemberObject_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574a90` |
| **VA** | `0x00574a90`–`0x00574af4` exclusive (**100 B**) |
| **Canonical name** | `VehicleCrew_ClearMemberObject_Inferred` |
| **Ghidra name** | `FUN_00574a90` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (Path A) |
| **Counterpart** | `reviews/B_aa_00574a90_VehicleCrew_ClearMemberObject_Inferred.md` |
| **System** | `skills-abilities` |
| **Agent** | WQ9D-G OWN-ONLY dual |
| **Verdict** | **accept-with-gaps** — CF/ABI/table/clear-partial/sole caller sealed; product English open |

---

## 1. Purpose

**Partial crew-member clear:** find candidate COID in host `+0x198` 4-slot table; null object* at `(slot+0x1A)*0x10`; set `candidate+0xCB0 = 0`; return bool. Not a full roster free (COID/count preserved).

```c
// __thiscall RET 4; AL bool
bool VehicleCrew_ClearMemberObject_Inferred(CrewHost* this, void* candidate);
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00574a90_FUN_00574a90.md` |
| Annotated | `docs/reconstruction/raw/aa_00574a90_FUN_00574a90.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/VehicleCrew_ClearMemberObject_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00574a90.cpp` |
| Live Ghidra | decompile + analyze complete + read_memory + xrefs |
| Sole caller | `Client_ClearObjectReferences` (`0x00944d50`) |
| Twins | Contains `0x005749d0`; Insert `0x005755b0`; setter `0x00520330` |

**Live re-decompile + body/callee bytes performed.** No `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `0x00574a90`–`0x00574af4` excl. | **Confirmed** | bounds + pad |
| `__thiscall` + `RET 4` | **Confirmed** | `C2 04 00` both exits |
| AL bool 0/1 | **Confirmed** | `32 C0` / `B0 01` |
| COID via offBase+0x164/0x168 | **Confirmed** | same as Contains |
| 4 slots × stride `0x10` @ `+0x198` | **Confirmed** | `cmp eax,4` / `jl` |
| object* zero @ `(i+0x1A)*0x10` | **Confirmed** | `add eax,0x1A; shl 4; mov [eax+esi],0` |
| `FUN_00520330(0)` this=candidate | **Confirmed** | ECX live through loop; callee writes `+0xCB0` |
| No COID free / no count-- | **Confirmed** | no stores to +0x198 pair / +0x1D8 |
| Sole caller ClearObjectReferences | **Confirmed** | 1 xref |
| Product C++ name | **Inferred** | |

---

## 4. Control flow

```
load candidate COID (SharedBase)
for i = 0..3:
  if host[0x198+i*0x10] matches COID:
    host[(i+0x1A)*0x10] = 0
    candidate+0xCB0 = 0
    return true
return false
```

### Client_ClearObjectReferences site

```
if destroyed.vtbl+0x1dc() && localPlayerObj && localPlayerObj+0xCB0:
  if ClearMemberObject(*(local+0xCB0), vtbl+0x1dc()):
    UI refresh
```

---

## 5. Gaps (acceptable)

1. Product English / MSVC demangle for crew-host class.  
2. Whether leaving COID occupied is intentional (destroy-only partial) vs missing free path.  
3. Insert twin dual is separate OWN (WQ9D-D).  
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps** under `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Live decompile ≡ raw CF | **Pass** |
| Bool return sealed | **Pass** |
| Partial-clear oddity documented | **Pass** |
| Callee this=candidate sealed | **Pass** |
| Clean meaningful names | **Pass** |
| Verdict | **accept-with-gaps** |
