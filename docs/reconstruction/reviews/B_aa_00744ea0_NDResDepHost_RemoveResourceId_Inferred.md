# Review B (skeptical / adversarial): `aa_00744ea0` NDResDepHost_RemoveResourceId_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00744ea0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W38-AE) |
| **Counterpart** | `reviews/A_aa_00744ea0_NDResDepHost_RemoveResourceId_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + xrefs + `get_assembly_context` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | cdecl / no this | **Falsified** — `MOV ESI,ECX`; recursive `MOV ECX,ESI` |
| 2 | Registration / insert of resource id | **Falsified** — only equal_range + `FUN_0044d630` erase + vector remove |
| 3 | Always cascades | **Falsified** — recurse gated (`CMP [ESP+0x34],0`); NDXml pushes **0** |
| 4 | Returns full EAX status code | **Falsified** — success path `MOV AL,[esp+0x13]`; fail `XOR AL,AL`; bool |
| 5 | `RET` without stack cleanup | **Falsified** — `C2 08 00` both exits |
| 6 | Scaffold TacArc Named_CalleeOf is precise | **Falsified** — reject long scaffold alias |
| 7 | Same as EffEffectSlot bind body | **Falsified** — bind is caller; this is dep remove helper |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| RET 8 + two stack formals | **High** | stack smash under NDXml / FX bind |
| Fail when map@+0x1c count remains | **High** | silent partial unbind |
| Erase-only (no insert) | **High** | port as register would invert lifecycle |
| Product class name | Medium | naming only |
| Recurse cascade graph shape | Medium | incomplete teardown if wrong |

---

## 3. Cross-check against raw + bytes

```
success=1
if equal_range(map@+0x1c, *pId).count == 1 && owned:
  erase that node
if equal_range count still != 0: return false
if *pId in vector[+0x50,+0x54): FUN_00744cc0
for node in equal_range(map head@+0x14, *pId):
  for entry in equal_range(map head@+0x20, node[6]):
    if entry[6]==*pId:
      erase entry
      if recurse: self(self, &node[6], 1)
      break
return success
RET 8
```

Clean must **not** insert nodes, use plain RET, or ignore the count≠0 fail path.

---

## 4. Surviving contract for AutoCore

```csharp
// Remove resource id from dependency host; optional cascade.
bool RemoveResourceId(DepHost host, int id, bool recurse)
{
    if (host.PrimaryMap.EqualRange(id).Count is var c && c > 1)
        return false;
    if (c == 1 && host.PrimaryMap.Single().OwnerId == host.SelfId)
        host.PrimaryMap.Erase(id);
    if (host.PrimaryMap.EqualRange(id).Count != 0)
        return false;
    host.TrackedIds.Remove(id);
    foreach (var node in host.DepMap.EqualRange(id))
    {
        foreach (var edge in host.RevMap.EqualRange(node.Key))
        {
            if (edge.Payload == id)
            {
                host.RevMap.Erase(edge);
                if (recurse) RemoveResourceId(host, node.Key, true);
                break;
            }
        }
    }
    return true;
}
```

Ports that treat this as add-ref/register, drop `RET 8`, or ignore the multi-hit fail will diverge under NDXml load and FX slot rebind notify paths.

---

## 5. Verdict

Adversarial falsifications reinforce erase-only thiscall contract; product English residual → **accept-with-gaps**.
