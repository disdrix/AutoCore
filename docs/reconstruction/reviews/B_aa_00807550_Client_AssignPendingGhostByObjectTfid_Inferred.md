# Review B (skeptical / independent): `aa_00807550` Client_AssignPendingGhostByObjectTfid_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00807550` |
| **VA** | `0x00807550` |
| **Canonical name** | `Client_AssignPendingGhostByObjectTfid_Inferred` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Skeptical naming / anti-overclaim |
| **Counterpart** | `reviews/A_aa_00807550_Client_AssignPendingGhostByObjectTfid_Inferred.md` |
| **System** | client net / pending ghost map (TFID) |
| **Verdict** | **accept-with-gaps** — agree with A |

---

## 1. Adversarial read of proposed names

| Candidate | Ruling |
|---|---|
| `FUN_00807550` only | Under-describes sealed ghost-assign consumer |
| `StdMap_Find_Tfid_Isnil29` (this VA) | **Reject** — that is dualed leaf `0x004cba00` |
| `Map_EraseNode_B` (this VA) | **Reject** — erase leaf is `0x00409220` |
| Vehicle-only create apply | **Narrow** — also called from `FUN_0080af70`; role is ghost-assign by TFID |
| Skill-hash / CNDHash lookup | **Reject** — dualed find is ordered map TFID isnil@+0x29 |
| `Client_AssignPendingGhostByObjectTfid_Inferred` | **Accept** — plate + find + assign + erase; `_Inferred` honest |

---

## 2. Attacks on A's CF claims

| Attack | Result |
|---|---|
| `__thiscall` ECX=host | **Fails** — host is **EAX**; object is stack; ECX reused for map/object |
| No stack cleanup | **Fails** — **`RET 4`** (`C2 04 00`) |
| Map at `manager+0x248` | **Fails** — map base `+0x244`; head at `+4` equals manager `+0x248` for end test only |
| Always erases | **Fails** — miss / `payload+0x5c != 0` skip |
| Inserts into map | **Fails** — only find + erase; no insert callee |
| Product English proven | **Fails** — keep `_Inferred` |
| Decompile `in_EAX` is wrong | **Fails** — register host ABI sealed by disasm + call sites (`MOV EAX,EBP/ESI`) |

---

## 3. Agreement with Review A

- Body/ABI/map/key/find/erase/string/callers: **agree Confirmed/High**  
- Name with `_Inferred`: **agree**  
- Gaps (vtbl English, payload type, runtime): **agree open**

---

## 4. Residual risks

- Do not merge this consumer with dualed find shell `004cba00` or erase `00409220`.  
- Do not claim vehicle-only without noting `FUN_0080af70` caller.  
- Do not invent product ghost class without PDB/runtime.

**Verdict:** **accept-with-gaps**
