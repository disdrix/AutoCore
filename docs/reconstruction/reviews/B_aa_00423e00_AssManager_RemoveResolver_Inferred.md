# Review B (skeptical / adversarial): `aa_00423e00` AssManager_RemoveResolver_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00423e00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W29-C) |
| **Counterpart** | `reviews/A_aa_00423e00_AssManager_RemoveResolver_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function is void(void) with no inputs | **Falsified** — bytes take **ECX=this**, **EAX=key**; sole caller loads both |
| 2 | Miss path throws / hard-fails | **Falsified** — log + return only; no `_CxxThrowException` |
| 3 | Erases all matching resolvers | **Falsified** — callees are first-equal find + first-equal erase |
| 4 | Container is free-standing global | **Falsified** — `ADD ESI, 0x58` off ECX this |
| 5 | This body also handles `[EBX+0xC]` path | **Falsified** — only one call site; parent inlines second key separately |
| 6 | Clean invents multi-list or CS logic | **Falsified** — CS lives in callees; body is find/branch/erase |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Register ABI ECX/EAX | **High** | Wrong key/manager → no-op or erase wrong list |
| Soft-fail miss | **High** | Invented throw breaks teardown flow |
| this+0x58 list | **High** | Port erases wrong member |
| Product English name | Medium | Rename-only residual |
| Key semantic type | Medium | Type confusion in managed port |

---

## 3. Cross-check against raw + bytes

```
PUSH ECX/ESI
MOV ESI, ECX; key_local = EAX; ADD ESI, 0x58
CALL find (EAX=ESI) → AL
  miss: vog_LogMessage(assManager.cpp, 0x27b, 3, "Removing resolver not found"); RET
  hit:  CALL EraseFirstEqual(&key); RET
```

Clean must keep **log-on-miss**, **single first-equal erase**, and **ECX/EAX** formals.

Do **not** invent erase-all, hard-fail, or ECX-only thiscall without EAX key.

---

## 4. Surviving contract for AutoCore

```csharp
// Port of AssManager_RemoveResolver_Inferred
void RemoveResolver(AssManager self, int resolverKey)
{
    var list = self.ResolversAt0x58; // GuardedVector family
    if (!list.ContainsFirstEqual(resolverKey))
    {
        Log("assManager.cpp", 0x27b, 3, "Removing resolver not found");
        return;
    }
    list.EraseFirstEqual(resolverKey);
}
```

Caller supplies manager instance + key (retail: global manager + object field at +8).

---

## 5. Open questions

1. Product method name / class layout beyond +0x58 list.
2. Whether key is raw object pointer or stable id (equality is dword).
3. Relationship of second parent path `[EBX+0xC]` list identity (out of OWN body).

**Verdict:** **accept**
