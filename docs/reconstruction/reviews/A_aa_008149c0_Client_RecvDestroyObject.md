# Review A (reconstruction fidelity): `aa_008149c0` Client_RecvDestroyObject

| Field | Value |
|---|---|
| **Stable ID** | `aa_008149c0` |
| **VA** | `0x008149c0` |
| **Canonical name** | `Client_RecvDestroyObject` |
| **System** | network-sector |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_008149c0_Client_RecvDestroyObject.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_008149c0_Client_RecvDestroyObject.md` (or FUN_ twin for auth string renames) |
| Raw | `docs/reconstruction/raw/aa_008149c0_Client_RecvDestroyObject.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_RecvDestroyObject.cpp` |


---

## 2. Purpose (from unit)

S2C destroy object: resolve TFID; destroy via world; special-case local vehicle TFID match without conn.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| TFID pair at packet+8/+0xc | **High** |  |
| ResolveObjectTarget named | **High** |  |
| Local vehicle TFID compare path | **High** |  |
| in_EAX client context | **Medium** | Register framing |
| Control flow preserved clean ≡ raw | **High** | Scaffold rewrite; no modernization rewrite of CF |
| Bit-for-bit / runtime / differential | **Open** | Deferred |

---

## 4. Control flow checklist

| Stage | Match |
|---|---|
| FUN_007a69d0() preamble | **Yes** (clean ≡ raw scaffold) |
| if no conn or conn vt+8 false: compare local vehicle TFID to pkt+8/+0xc; maybe FUN_00802170 | **Yes** (clean ≡ raw scaffold) |
| else CVOGReaction_ResolveObjectTarget then destroy path | **Yes** (clean ≡ raw scaffold) |

---

## 5. Gaps

1. Destroy cascade full callees
2. packet+0x10 type byte meaning
3. FUN_00802170 identity

**Verdict:** **accept-with-gaps**
