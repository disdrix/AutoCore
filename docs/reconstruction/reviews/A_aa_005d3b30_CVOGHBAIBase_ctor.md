# Review A (reconstruction fidelity): `aa_005d3b30` CVOGHBAIBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d3b30` |
| **VA** | `0x005d3b30` |
| **Canonical name** | `CVOGHBAIBase_ctor` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_005d3b30_CVOGHBAIBase_ctor.md` |
| **System** | `npc-ai` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Construct base HBAI: vtable `PTR_LAB_009daad0`, zero target/owner/range slots, default floats from `g_flOne`, copy owner/context block from param_2. Parent for CreatureBase / CharacterOrMine / Bot factories.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_005d3b30_CVOGHBAIBase_ctor.md` |
| Annotated | `docs/reconstruction/raw/aa_005d3b30_CVOGHBAIBase_ctor.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBAIBase_ctor.cpp` |
| Function record | `docs/reconstruction/functions/aa_005d3b30_CVOGHBAIBase_ctor.md` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `Vtbl PTR_LAB_009daad0` | **High** | Store *this |
| `Zeros target/range slots +0x08.. family` | **High** | Many stores |
| `g_flOne into scale slots (param_1[3])` | **High** | Default 1.0 |
| `Copies param_2 quad into +0x18.. then clears some` | **High** | Owner/context seed |
| `Returns this` | **High** | thiscall |
| `Parent of factory subclasses` | **High** | Call graph |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Vtbl + zero + g_flOne | **Yes** |
| param_2 copy | **Yes** |
| No invented fields | **Yes** |

---

## 5. Gaps / open

1. Full field name map for +0x08..+0x7c.
2. param_3 role (often unused/residual).
3. Which slots FindTarget/GetTargetFromAggro require post-init.

**Verdict:** **accept-with-gaps**
