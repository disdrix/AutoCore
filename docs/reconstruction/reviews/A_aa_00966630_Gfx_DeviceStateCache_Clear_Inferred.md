# Review A (reconstruction fidelity): `aa_00966630` Gfx_DeviceStateCache_Clear_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00966630` |
| **VA** | `0x00966630`–`0x00966674` exclusive (**68 B** / `0x44`) |
| **Canonical name** | `Gfx_DeviceStateCache_Clear_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00966630` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W38-Y) |
| **Counterpart** | `reviews/B_aa_00966630_Gfx_DeviceStateCache_Clear_Inferred.md` |
| **System** | gfx / device state cache clear |
| **Evidence pass** | Live Ghidra decompile + `read_memory` (68 B full) + sole caller site + sibling `FUN_00966690` + consumer `FUN_0043f4b0`. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

**Clear device-bound state caches** after successful D3D device Reset:

1. Zero global **16-stage** texture/object caches (`DAT_00d0e128`, `DAT_00d0e0e8`).
2. Zero four scalar cache globals.
3. Zero host slots `+0/+4/+8/+0x3C` (EDX = `DAT_00d1f048`).

Parent `GfxDevice_Reset` then republishes host[0..2] from recreated surfaces/state.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W38-Y append) | `docs/reconstruction/raw/aa_00966630_FUN_00966630.md` |
| Annotated | `docs/reconstruction/raw/aa_00966630_FUN_00966630.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Gfx_DeviceStateCache_Clear_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00966630.cpp` |
| Function record | `docs/reconstruction/functions/aa_00966630_FUN_00966630.md` |
| Named record | `docs/reconstruction/functions/aa_00966630_Gfx_DeviceStateCache_Clear_Inferred.md` |
| Parent dual | `aa_0075eff0` `GfxDevice_Reset` (W37-N) |
| Live | decompile CF ≡ bytes; phantom ECX dropped |

---

## 3. Signature (sealed)

```c
// EDX=host*; ECX unused; plain RET; void; leaf
void Gfx_DeviceStateCache_Clear_Inferred(uint32_t *host);
```

| Formal | Source | Conf |
|---|---|---|
| host (EDX) | Stores to `[EDX]`/`[EDX+4]`/`[EDX+8]`/`[EDX+0x3C]`; caller `MOV EDX,[DAT_00d1f048]` | **High** |
| ECX | never read/written | **phantom — drop** |
| return | void | **High** |
| convention | no stack args; `C3` | **High** |

---

## 4. Control flow (decompile + bytes authority)

```
PUSH ESI; PUSH EDI
ESI=0; EAX=0
REP STOSD DAT_00d0e128 × 16
REP STOSD DAT_00d0e0e8 × 16
POP EDI
store ESI→ DAT_00d1a568, DAT_00d1a564, DAT_00d1a558, DAT_00d1a55c
store ESI→ host[0], host[1], host[2], host[0xf]
POP ESI; RET
```

| Stage | Match | Conf |
|---|---|---|
| Dual 16-dword zero | Yes (`ECX=0x10`, `REP STOSD`) | **High** |
| Four scalars | Yes | **High** |
| Four host dwords | Yes (+0x3C = index 0xF) | **High** |
| Stage tables = texture cache | `FUN_0043f4b0` stage-index compare + D3D `vtbl+0x190` | **High** |

---

## 5. Gaps (accepted)

- Product English for host class (Stats Monitor vs generic state tracker).
- Scalar global product names.
- Runtime / bit-exact.

---

## 6. Verdict rationale

Leaf body fully sealed by bytes; sole caller + twin init + stage-cache consumers give strong structural role. Name remains `_Inferred` without overclaiming product English. **accept**.
