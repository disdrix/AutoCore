# Review B (skeptical / adversarial): `aa_0044af00` Phy_CPConnection_AssertConnectionPoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044af00` |
| **VA** | `0x0044af00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (machine seal; prior 2026-07-23 string scaffold) |
| **Counterpart** | `reviews/A_aa_0044af00_Phy_CPConnection_AssertConnectionPoint.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` + caller assembly context (no `disassemble_bytes`) |
| **Verdict** | **accept-with-gaps** on CF; **High** on multi-reg ABI, −1 none-path, log miss, refcount swap |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Standard `__fastcall` with one ECX formal only | **Falsified** — machine uses **EAX** id, **ECX** owner, **EBX** smart slot, **EDI** owner-out; `ret` not `ret 4` |
| 2 | `unaff_EBX` / `unaff_EDI` are decompiler garbage | **Falsified as garbage** — every live call site loads EBX/EDI before CALL; they are **real formals** |
| 3 | `connId == -1` is an error | **Falsified** — no log; returns **0**; clears smart ptr (explicit none) |
| 4 | Always logs on every call | **Falsified** — log only on lookup miss |
| 5 | Lookup this is owner itself | **Falsified** — `lea ecx,[esi+0x64]` then thiscall `0040d4b0` |
| 6 | Return value is the connection object | **Falsified** — EAX is **status** (0 / −1); object written through **\*EBX** |
| 7 | AddRef always calls virtual | **Falsified** — virtual **vtbl+4** only when count becomes **1** after ++ |
| 8 | Miss leaves prior smart ptr intact | **Falsified** — Release + null slot; `*EDI=0` |
| 9 | Function is void / no meaningful return | **Falsified** — callers `TEST EAX` / `CMP` both returns against 0 before continue |
| 10 | Body larger than ~0x98 / multi-exit thunk | **Falsified** — ends `0x0044af97`, `CC` pad; single function |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Multi-reg formals | **High** | Wrong port ABI / stack trash |
| −1 = success none | **High** | Treat none as assert fail |
| Miss = log + −1 | **High** | Silent fail / wrong severity |
| owner+0x64 registry | **High** | Search wrong list |
| Refcount @ object+4; vtbl+8 destroy | **High** | Leak / double-free |
| vtbl+4 first-acquire only | **High** | Extra side effects on every bind |
| Object type / id taxonomy | **Tentative / Open** | Wrong domain mapping |

---

## 3. Cross-check against raw / machine

```
if connId == -1:
  *pOutOwner = owner
  Release(*pSmart); *pSmart = null; return 0

node = FindById(owner+0x64, connId)   // 0040d4b0 thiscall
if node:
  *pOutOwner = owner
  obj = *node                          // payload object*
  if obj: AddRef(obj); if first: vtbl+4
  Release(*pSmart); *pSmart = obj; return 0

log phyCPConnection.h:143 level3 "Connection point not found!"
*pOutOwner = null; Release(*pSmart); *pSmart = null; return -1
```

Raw decompile CF matches machine once `in_EAX`/`unaff_*` are read as formals. Clean plate post-seal ≡ machine.

---

## 4. Surviving contract for AutoCore

```
// Custom multi-register (not MSVC thiscall alone):
//   EAX = connectionPointId  (-1 = explicit none)
//   ECX = owner*
//   EBX = RefCountedObject**  // out smart-pointer slot
//   EDI = void**              // out owner mirror
//   returns int: 0 ok, -1 not found

int Phy_CPConnection_AssertConnectionPoint(
    int connectionPointId /*EAX*/,
    Owner* owner /*ECX*/,
    RefCountedObject** pSmartSlot /*EBX*/,
    void** pOutOwner /*EDI*/)
{
  if (connectionPointId == -1) {
    *pOutOwner = owner;
    ReleaseSlot(pSmartSlot);
    return 0;
  }
  ListNodePayload* hit = FindConnectionPointById(owner + 0x64, connectionPointId);
  if (hit) {
    *pOutOwner = owner;
    RefCountedObject* obj = hit->pObject; // *hit
    AddRefFirstAcquire(obj);              // ++@+4; vtbl+4 if 1
    ReplaceSlot(pSmartSlot, obj);         // Release old; store new
    return 0;
  }
  vog_LogMessage("..\\palantir/physics/phyCPConnection.h", 0x8f, 3,
                 "Connection point not found!");
  *pOutOwner = nullptr;
  ReleaseSlot(pSmartSlot);
  return -1;
}
```

Callers often bind **two** ids into a 16-byte pair and require **both** returns 0.

---

## 5. Open questions

1. C++ type name for objects living in the `+0x64` registry list.
2. Connection-point id constants (0, 0x1F, 0x23, …) → bone/hardpoint meaning.
3. Whether first-acquire vtbl+4 is load-on-demand (geo/physics) vs pure refcount.

**Verdict:** **accept-with-gaps** on CF; **High** on ABI, −1 none, miss log/−1, refcount swap
