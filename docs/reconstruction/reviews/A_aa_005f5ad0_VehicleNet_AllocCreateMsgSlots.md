# Review A (reconstruction fidelity): `aa_005f5ad0` VehicleNet_AllocCreateMsgSlots

| Field | Value |
|---|---|
| **Stable ID** | `aa_005f5ad0` |
| **VA** | `0x005f5ad0` |
| **Canonical name** | `VehicleNet_AllocCreateMsgSlots` (inferred; Ghidra `FUN_005f5ad0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005f5ad0_VehicleNet_AllocCreateMsgSlots.md` |
| **System** | input-drive-control / GhostVehicle unpack create templates |
| **Evidence pass** | Live `batch_decompile` + xrefs; opcode sizes match `CLoadNode::setCreateMsg` dual (`0x2012`/`0xD8`, `0x2013`/`0x930`, `0x2015`/`0x1a8`); sole caller `VehicleNet_UnpackGhostVehicle` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Replace/create message template buffers** on a GhostVehicle-side host (`this`):

### Branch A — `param_2 == 0` (vehicle create slot `this+0x5c`)

1. `operator_delete` prior `this+0x5c` if non-null (decomp “does not return” is **false**).
2. `operator_new(0xD78)` + `FUN_00506ee0` (ctor) else null.
3. Zero **0x35E** dwords (0xD78 bytes).
4. Stamp opcodes / sentinels:
   - `*buf = 0x201D` (primary vehicle create family)
   - nested `+0x708 = 0x201C`, three stride-`0x62` blocks at `+0x890` each `* = 0x201C`
   - nested simple object `+0x158 = 0x2012`
   - `+0x458 = 0x201B`, `+0x5B0 = 0x2060`
   - many COID/TFID-like fields = **−1**; floats `g_flOne` at `+0x80`, `+0x4D8`; flag `+0x4F8 = 1`

### Branch B — `param_2 != 0` (owner/create slot `this+0x60`)

1. Delete prior `this+0x60`.
2. If `param_3 != 0`: alloc **0x930**, zero **0x24C** dwords, `*buf = 0x2013` (character create — matches setCreateMsg large path), stamp −1 / `g_flOne` / ms-to-sec pre-init fields.
3. Else: alloc **0x1A8**, zero **0x6A** dwords, `*buf = 0x2015`, set bit on `+0x129`, stamp −1 / one.

Pre-zero partial inits (indices 0x19–0x1F) set before the bulk zero loop — bulk zero **overwrites** them; only values written **after** the zero loop stick. The pre-loop stores of `g_flMsToSeconds_Inferred` at `[0x1f]` are therefore dead unless ctor path differs (live CF shows zero after).

**Caller:** `VehicleNet_UnpackGhostVehicle` only (3 xrefs).

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005f5ad0_FUN_005f5ad0.md` |
| Annotated | `docs/reconstruction/raw/aa_005f5ad0_FUN_005f5ad0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005f5ad0.cpp` |
| Function record | `docs/reconstruction/functions/aa_005f5ad0_FUN_005f5ad0.md` |
| Related | `reviews/A_aa_005c6c70_Named_LoadNode_setCreateMsg.md` |

**Three-rep:** present.

---

## 3. Signature

```c
void __thiscall VehicleNet_AllocCreateMsgSlots(void *ghostHost, char useOwnerSlot, char isCharacterLarge);
// param_2==0 → this+0x5c vehicle 0xD78 / 0x201D
// param_2!=0 && param_3!=0 → this+0x60 char 0x930 / 0x2013
// param_2!=0 && param_3==0 → this+0x60 alt 0x1A8 / 0x2015
```

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Triple branch on (param_2, param_3) | **Yes** | **High** |
| Sizes 0xD78 / 0x930 / 0x1A8 | **Yes** | **High** |
| Opcodes 0x201D / 0x2013 / 0x2015 (+ nested) | **Yes** | **High** |
| Zero dword counts 0x35E / 0x24C / 0x6A | **Yes** | **High** |
| Replace delete-then-new on slot | **Yes** | **High** |
| Clean ≡ raw | **Yes** | **High CF** |

### Decompiler hazards

- `operator_delete` “does not return” — **false**.
- Pre-zero field writes before bulk zero are **dead** in this CF (note residual).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Create-msg template allocator for ghost unpack | **High** | opcodes + sizes vs setCreateMsg |
| Slot +0x5c vehicle vs +0x60 owner | **High** | branch layout |
| Nested 0x2012/0x201C/0x201B/0x2060 in vehicle blob | **High** | live stores |
| Exact product message names | **Probable** | 0x201D residual English |
| Dead pre-zero ms fields | **High** | CF order |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Name 0x201D / nested 0x201C vehicle sub-messages formally.
2. Confirm `FUN_00506ee0` side effects beyond allocation for 0xD78 path.
3. Whether bulk zero intentionally wipes pre-inits (compiler artifact vs intended).

**Verdict:** **accept-with-gaps**
