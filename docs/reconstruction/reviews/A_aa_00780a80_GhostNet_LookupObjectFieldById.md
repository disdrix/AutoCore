# Review A (reconstruction fidelity): `aa_00780a80` GhostNet_LookupObjectFieldById

| Field | Value |
|---|---|
| **Stable ID** | `aa_00780a80` |
| **VA** | `0x00780a80` |
| **Canonical name** | `GhostNet_LookupObjectFieldById` (inferred; Ghidra `FUN_00780a80`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00780a80_GhostNet_LookupObjectFieldById.md` |
| **System** | network-ghost / object id map |
| **Evidence pass** | Live `batch_decompile` + callers (ghost unpack family) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Resolve a net/object id against a host hash table**, returning a dword field or sentinel.

```
if id == 0: return 0xFFFFFFFF
if this+0x208 == 0:   // map inactive / passthrough mode
  return *(uint*)(id + 0x20)   // treat id as object*; read field +0x20
else:
  bucket = *(this+0x224 + (id & 0x3FF)*4)   // 1024 buckets
  for node in chain (node[8] next):
    if node[0]==id AND (node[10] & 0x3C)==0:
      return node[0xC]
  return 0xFFFFFFFF
```

**Callers:** `FUN_005b17b0` Net_UnpackGhostUpdate, `GhostCreature_UnpackUpdate`, `VehicleNet_UnpackGhostVehicle`, `FUN_0060a820`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00780a80_FUN_00780a80.md` |
| Annotated | `docs/reconstruction/raw/aa_00780a80_FUN_00780a80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_00780a80.cpp` |
| Function record | `docs/reconstruction/functions/aa_00780a80_FUN_00780a80.md` |

**Three-rep:** present.

---

## 3. Signature

```c
uint __thiscall GhostNet_LookupObjectFieldById(void *host, uint idOrObjectPtr);
// returns field dword or 0xFFFFFFFF
```

| Formal | Source | Conf |
|---|---|---|
| `this+0x208` mode gate | live | **High** |
| `this+0x224` bucket base | live | **High** |
| mask `0x3FF` (1024) | live | **High** |
| flag reject `node[10] & 0x3C` | live | **High** |
| return `node[0xC]` | live | **High** |
| passthrough `*(id+0x20)` | live | **High CF / Tentative meaning** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| id==0 → −1 | **Yes** | **High** |
| +0x208==0 passthrough +0x20 | **Yes** | **High** |
| hash chain walk + flag gate | **Yes** | **High** |
| miss → −1 | **Yes** | **High** |
| No callees (leaf) | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| 1024-bucket id hash lookup | **High** | body |
| Reject nodes with `(flags&0x3C)!=0` | **High** | live |
| Used by all major ghost unpack paths | **High** | callers |
| Semantic of returned dword (handle vs TFID half) | **Tentative** | consumers not dual-sealed here |
| Passthrough mode meaning | **Probable** | residual |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. Name host class owning +0x208/+0x224.
2. Seal consumer use of returned value in each unpacker.
3. Flag bits in `node[10] & 0x3C` (deleted / pending / type).

**Verdict:** **accept-with-gaps**
