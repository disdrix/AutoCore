# Review A (reconstruction fidelity): `aa_007971b0` Dword4_Copy

| Field | Value |
|---|---|
| **Stable ID** | `aa_007971b0` |
| **VA** | `0x007971b0` |
| **Canonical name** | `Dword4_Copy` (inferred; Ghidra `FUN_007971b0`) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_007971b0_Dword4_Copy.md` |
| **System** | shared / create-packet + ghost unpack |
| **Evidence pass** | Live `batch_decompile`; callers CreateSimpleObject_Serialize(+Variant2), ghost unpack, skill path |
| **Verdict** | **accept** |

---

## 1. Purpose

**Copy exactly four dwords** from `src` to `dst`:

```
dst[0]=src[0]; dst[1]=src[1]; dst[2]=src[2]; dst[3]=src[3];
```

Typical uses: position/rotation/TFID-shaped 16-byte pods in CreateSimpleObject serialize and ghost update paths. No validation, no scale, no endian transform.

**Callers (sample):** `CreateSimpleObject_Serialize`, `CreateSimpleObject_SerializeVariant2`, `GhostCreature_UnpackUpdate`, `VehicleNet_UnpackGhostVehicle`, `FUN_005b17b0`, `FUN_0060a820`, `FUN_00626400`, `FUN_00814530`, `FUN_004c3d60`.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_007971b0_FUN_007971b0.md` |
| Annotated | `docs/reconstruction/raw/aa_007971b0_FUN_007971b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007971b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007971b0_FUN_007971b0.md` |

**Three-rep:** present.

---

## 3. Signature

```c
void __thiscall Dword4_Copy(uint32_t *dst /* ECX */, uint32_t *src /* stack */);
// decompiler may show thiscall; role is pure 16-byte copy (dst, src)
```

Note: MSVC thiscall with dst in ECX is consistent with “member assign” sugar; behavior is free-function equivalent.

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match | Conf |
|---|---|---|
| Four dword stores | **Yes** | **High** |
| No branches / callees | **Yes** | **High** |
| Clean ≡ raw | **Yes** | **High** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Exact 4×u32 copy | **High** | trivial body |
| Used for 16-byte pods across net | **High** | callers |
| Specific pod type (TFID vs vec4) | **context-dependent** | callers decide |
| Runtime | **Open** | unnecessary for CF seal |

---

## 6. Gaps

1. Optional rename per call-site pod type only — body stays generic.

**Verdict:** **accept**
