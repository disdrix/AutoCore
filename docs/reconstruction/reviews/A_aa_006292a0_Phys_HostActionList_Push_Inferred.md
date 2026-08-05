# Review A (reconstruction fidelity): `aa_006292a0` Phys_HostActionList_Push_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006292a0` |
| **VA** | `0x006292a0` |
| **Canonical name** | `Phys_HostActionList_Push_Inferred` |
| **Ghidra name** | `FUN_006292a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual A/B) |
| **Counterpart** | `reviews/B_aa_006292a0_Phys_HostActionList_Push_Inferred.md` |
| **System** | `physics` (host action list / applyAction feed) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

MSVC **thiscall** append of an **action\*** (or similar child object) onto the growable **pointer array at `host+0x4c`**, then write **owner back-link** `action+0x10 = host`.

This is the list that island integrate walks to dispatch **`vtbl+0x14` applyAction** (e.g. `VehicleAction` @ `0x00598650`). Registration path: `Vehicle_createVehicleAction` → `Phys_RegisterAction` → **this VA** (see `physics/0.1-step-rate.md`).

Not body-pair glue (`0055efd0`). Not post-register notify (`0062a3d0`). Not host activate.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006292a0_FUN_006292a0.md` |
| Annotated | `docs/reconstruction/raw/aa_006292a0_FUN_006292a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_006292a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_006292a0_FUN_006292a0.md` |
| Live decompile | Ghidra MCP `batch_decompile` @ `0x006292a0` |
| Bytes | `read_memory` 64 B — full-path grow; epilogue **`C2 04 00` ret 4** |
| Call-site ABI | `get_assembly_context` @ `0x0055feac` — `PUSH action; MOV ECX, host; CALL` |
| Parent dual | `A\|B_aa_0055fe50_Phys_RegisterAction` |
| Grow helper dual | `A\|B_aa_005b3370_GrowableArray_DoubleGrow` |
| Step chain | `physics/0.1-step-rate.md`, `fn_00561910_islandStep.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` ECX = **host** (sim host / island node); stack = **action\***; **`ret 4`** | **Confirmed** | RegisterAction site `MOV ECX,ESI` (host from `body+0x44`); `C2 04 00` |
| Header at `this+0x4c`: `{void* data; int count; int capRaw}` | **Confirmed** | body `+0x4c/+0x50/+0x54` |
| Full when `count == (capRaw & 0x7fffffff)` | **Confirmed** | |
| Grow: `FUN_005b3370(hdr, 4)` — double capacity, elem size 4 | **Confirmed** | matches DoubleGrow dual |
| `data[count] = action; count++` | **Confirmed** | |
| `action+0x10 = host` back-link | **Confirmed** | `mov [eax+0x10], edi` with edi=this |
| Role = **host action list push** for later applyAction | **High** | RegisterAction + step-rate chain |
| Prior doc “world+0x4c” | **Corrected** | live sites pass **host** in ECX (host may be world sub-object; offset still `+0x4c` on ECX) |
| Product / PDB name | **Open** | `_Inferred` |
| Element type always VehicleAction | **Open** | also flipper / other RegisterAction callers |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Compare count vs masked cap | Yes |
| If full → `005b3370(hdr, 4)` | Yes |
| Store pointer at `data[count]` | Yes |
| Increment count | Yes |
| Backlink `child+0x10 = this` | Yes |
| `ret 4` | Yes |

### Recovered CF

```c
// void __thiscall Phys_HostActionList_Push_Inferred(Host *host, void *action)
// RET 4
void Phys_HostActionList_Push_Inferred(void *host, void *action)
{
  int *hdr = (int *)((char *)host + 0x4c);  // [0]=data, [1]=count, [2]=capRaw
  if ((unsigned)hdr[1] == ((unsigned)hdr[2] & 0x7fffffff))
    FUN_005b3370(hdr, /*elemSize=*/4);

  void **data = *(void ***)hdr;
  int count = hdr[1];
  data[count] = action;
  hdr[1] = count + 1;
  *(void **)((char *)action + 0x10) = host;
}
```

---

## 5. Callers

| Caller | Site | Notes |
|---|---|---|
| `Phys_RegisterAction` `0x0055fe50` | `0x0055feac` | First valid collected host: push **action**; ECX=host |
| `FUN_00560f70` | `0x005611e5` | Re-home / match action onto host list |
| `FUN_00561580` | `0x00561716` | Related host detach/reattach path |

**3 UNCONDITIONAL_CALL xrefs.**

---

## 6. Gaps

1. Product name for host action list API.
2. Whether every element is always an “action” with `vtbl+0x14` applyAction (High for VehicleAction path; other types open).
3. Clarify host vs world object identity for `+0x4c` across all island layouts.
4. Runtime / bit-exact open.

**Verdict:** CF + ABI + backlink + grow sealed. **accept-with-gaps.**
