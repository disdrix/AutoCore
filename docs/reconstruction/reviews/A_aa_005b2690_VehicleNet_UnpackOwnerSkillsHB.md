# Review A (reconstruction fidelity): `aa_005b2690` VehicleNet_UnpackOwnerSkillsHB

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b2690` |
| **VA** | `0x005b2690` |
| **Canonical name** | `VehicleNet_UnpackOwnerSkillsHB` (inferred; Ghidra `FUN_005b2690`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005b2690_VehicleNet_UnpackOwnerSkillsHB.md` |
| **System** | input-drive-control / GhostVehicle unpack / skills HB |
| **Evidence pass** | Live `batch_decompile` + callees/callers; pack twin `aa_005b2830`; parent `aa_005f7720` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Owner skills / HB blob list unpack** — mirror of `VehicleNet_PackOwnerSkillsHB` (`0x005b2830`).

Wire:

1. **u8 count** (`BitStream_readBits(8)`)
2. If count == 0 → return
3. Else `count` times:
   - **u16 size** (`BitStream_readBits(0x10)`)
   - `malloc(size)`
   - `FUN_005b1570(stream, buf, size)` — bulk bit-copy into buffer
   - Build **0x18** node + **0x18** ByteBuffer (vtbl `PTR_LAB_009d7b00`), attach buffer owns=1, size=size
   - Node fields: `[0]=-1`, `[1]=0`, `[2]=ByteBuffer*` (refcount++), `[3]=data*`, `[4]=0x40` (bit cursor seed)
   - `FUN_005b2d70(&node)` — insert/enqueue into owner HB collection

**Callers:** `VehicleNet_UnpackGhostVehicle`, `GhostCreature_UnpackUpdate`, `FUN_0060a820`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005b2690_FUN_005b2690.md` |
| Annotated | `docs/reconstruction/raw/aa_005b2690_FUN_005b2690.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_005b2690.cpp` |
| Function record | `docs/reconstruction/functions/aa_005b2690_FUN_005b2690.md` |
| Pack twin dual | `reviews/A_aa_005b2830_VehicleNet_PackOwnerSkillsHB.md` |

**Three-rep:** present.

---

## 3. Signature

```c
// stack BitStream* (thiscall subcalls); decompiler may collapse stream into ECX chain
void VehicleNet_UnpackOwnerSkillsHB(BitStream *stream /*, owner context */);
```

| Formal | Source | Conf |
|---|---|---|
| stream | stack → ESI path; BitStream_readBits thiscall | **High** |
| collection target | via `FUN_005b2d70` side effect | **High role / Tentative layout** |
| Epilogue | SEH frame + restore ExceptionList | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| u8 count gate | **Yes** | **High** |
| per-entry u16 size + malloc + bulk read | **Yes** | **High** |
| ByteBuffer wrap vtbl `009d7b00` | **Yes** | **High** |
| node `+0x10` cursor `0x40` | **Yes** | **High** |
| insert via `FUN_005b2d70` | **Yes** | **High** |
| No identity seed fields | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Skills/HB blob list unpack | **High** | CF vs identity twin |
| Wire: u8 count × {u16 size + payload bits} | **High** | live |
| ByteBuffer ownership | **High** | owns flag + free path |
| Payload internal skill encoding | **Open** | deferred to `FUN_005b1570` / consumers |
| Product name | **Tentative** | inferred from pack twin |
| Runtime | **Open** | deferred |

---

## 6. Gaps

1. `FUN_005b2d70` destination container type (map vs list) not dual-sealed here.
2. Payload bytes are opaque blobs — not skill opcode dictionary.
3. Pack twin path may interleave CS/critical section not mirrored 1:1 in this reader.

**Verdict:** **accept-with-gaps**
