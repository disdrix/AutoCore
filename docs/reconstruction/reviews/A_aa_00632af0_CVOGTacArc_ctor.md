# Review A (reconstruction fidelity): `aa_00632af0` CVOGTacArc_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00632af0` |
| **VA** | `0x00632af0` |
| **Canonical name** | `CVOGTacArc_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00632af0_CVOGTacArc_ctor.md` |
| **System** | `client-ui` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct tactical-arc visual object (vehicle weapon cone UI). Installs vtbl `PTR_CVOGTacArc_vdtor_009e3538`; seeds RGBA color bytes **+0x30..+0x3f** to 0xFF then later palette defaults; dual `FUN_0096ef70` + `FUN_0096f530` sub-object inits; zeros mesh/runtime slots; seeds `param_1[2]=g_flOverheatCoolFrac`, `param_1[10]=0x32` (segments/count), color default pack ending in ctor body. Client-only render helper — not server combat math.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00632af0_CVOGTacArc_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_00632af0_CVOGTacArc_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGTacArc_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_00632af0_CVOGTacArc_ctor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl PTR_CVOGTacArc_vdtor_009e3538` | **High** | Store *this |
| `Byte color pad +0x30..+0x3f init 0xFF then defaults` | **High** | Body |
| `FUN_0096ef70 x2 + FUN_0096f530 sub-inits` | **High** | SEH staged |
| `param_1[2]=g_flOverheatCoolFrac` | **High** | Float seed |
| `param_1[10]=0x32 (50) segment/default` | **High** | Literal |
| `Zeros +0x18 mesh / +0x1c mat slots family` | **High** | param_1[6..8,0xb] |
| `Returns this` | **High** | Ctor ABI |
| `Not network / not damage arc math` | **High** | No wire callees |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| SEH + vtbl + color seed + helpers | **Yes** |
| No invented combat logic | **Yes** |

---

## 5. Gaps / open

1. Exact object size and full field map for mesh/mat pointers.
2. FUN_0096ef70 / FUN_0096f530 identity (embedded CVOG subobjects).
3. Whether g_flOverheatCoolFrac is shared with weapon overheat UI.

**Verdict:** **accept-with-gaps**
