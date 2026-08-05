# Review A (reconstruction fidelity): `aa_009332b0` Auth_No_authentication_key

| Field | Value |
|---|---|
| **Stable ID** | `aa_009332b0` |
| **VA** | `0x009332b0` |
| **Canonical name** | `Auth_No_authentication_key` |
| **System** | auth |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009332b0_Auth_No_authentication_key.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_009332b0_*.md` (or FUN_ twin) |
| Clean | `docs/reconstruction/reconstructed-exact/Auth_No_authentication_key.cpp` |
| String / plate evidence | From clean header + body |

---

## 2. Purpose (from unit)

Auth-key missing path: FUN_0092f360(); set object +0xc0=2, +0xc4=3; if both +0x113 and +0xa6 are 0, toast/debug FUN_007a4480(1, 'No authentication key'); then FUN_00807490(obj+0x730, 0x6900). Client state + notify — not full AuthClient packet table.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| String 'No authentication key' | **High** | Literal |
| Writes +0xc0=2 and +0xc4=3 | **High** | Direct stores |
| Toast gated on +0x113==0 && +0xa6==0 | **High** | if condition |
| FUN_00807490(base+0x730, 0x6900) always after | **High** | tail call |
| FUN_0092f360 first | **Medium** | side effects open |
| in_EAX is host object | **Medium** | register this |
| Control flow preserved clean ≡ raw scaffold | **High** | No modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| precall → set two dwords → conditional message → FUN_00807490 | **Yes** |
| No loop / no multi-branch table | **Yes** |

---

## 5. Gaps

1. Meaning of state codes 2/3 at +0xc0/+0xc4 open.
2. 0x6900 argument to FUN_00807490 (opcode? size? flag?) open.
3. Relationship to real auth-key storage open.
4. Address-suffixed twin same VA.

**Verdict:** **accept-with-gaps**
