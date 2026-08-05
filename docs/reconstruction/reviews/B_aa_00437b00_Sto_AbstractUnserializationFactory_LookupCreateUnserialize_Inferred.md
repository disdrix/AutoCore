# Review B (skeptical / adversarial): `aa_00437b00` Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00437b00` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W36-A) |
| **Counterpart** | `reviews/A_aa_00437b00_Sto_AbstractUnserializationFactory_LookupCreateUnserialize_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ sample creator + caller site bytes). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function **is** PeekChunkTag | Body calls Peek then map lookup/create/vfunc | **Falsified** — consumer of Peek, not Peek itself |
| 2 | Function is insert/register path | No log strings; no `FUN_0046bf90`; reads `node+0xc` | **Falsified** — insert is `FUN_004449b0` |
| 3 | Creator is called as `creator(tag)` | Bytes: `FF 51 0C` with zero pushes; sample `FUN_00444d00(void)` | **Falsified** — **0-arg** creator |
| 4 | ECX-thiscall on factory | Map from GetInstance; out on stack; EDI reader | **Falsified** — cdecl + EDI register |
| 5 | Uses MapB | GetInstance targets `0x00438c40` only | **Falsified** — Map A |
| 6 | Returns created object pointer | Success returns **vfunc status**; object stored via `*out` | **Falsify if treated as object return** |
| 7 | Fail returns 0 | Fail path `OR EAX, -1` | **Falsified** — **`0xFFFFFFFF`** |
| 8 | gfxBody scaffold name = graphics unit | No gfx ops in body; storage factory + chunk | **Over-narrow** — reject product role |
| 9 | Vfunc this = object base | `LEA ECX,[EAX+4]` — subobject at **+4** | **Clarify** — this is `obj+4` |
| 10 | Consumes chunk permanently in Peek | Peek restores cursor (sealed Peek unit) | **No** — peek is non-destructive; vfunc may consume |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| EDI reader + stack out* | **High** | Wrong object slot / null reader |
| Peek → lookup → create → vfunc order | **High** | Port reorders → stream desync |
| Creator 0-arg @ `node+0xc` | **High** | Passing tag corrupts stack |
| Return status vs object | **High** | Caller ORs status; mistaking for ptr breaks flags |
| Fail = `-1` | **High** | Treating 0 as fail misses miss path |
| Vfunc this=`obj+4` | **High** | Wrong this → crash |
| Object class English | **Low/Inferred** | Doc only |
| Map-op internals | **Medium** | Unowned |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  tag = Peek()
  lookup; if sentinel: obj=0 else obj=creator(tag)  // tag arg SUSPECT
  *out = obj
  if obj: return vfunc()
  return -1

bytes:
  MOV ESI,EDI
  CALL PeekChunkTag          ; tag local
  CALL MapA; CALL lookup
  CALL MapA; CMP node, sentinel
  JE null
  CALL [node+0xC]            ; NO push of tag
  *out = EAX
  JE fail
  LEA ECX,[obj+4]; PUSH EDI; CALL [vtbl+4]
  RET status
fail: OR EAX,-1; RET
```

Clean must **not** invent:

- Insert/log path / MapB
- Creator stack argument = tag
- Returning object in EAX instead of status
- Fail return 0
- this = object base (not +4)
- Graphics geometry work

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x00437b00
// reader in register corresponding to EDI; out on stack
static uint Sto_AbstractUnserializationFactory_LookupCreateUnserialize(
    ref object outObj, StoChunkReader reader)
{
    var tag = stoChunkReader_PeekChunkTag(reader); // FUN_0076a900, ESI=this
    var map = Sto_UnserialFactoryMapA_GetInstance(); // FUN_00438c40
    var node = NestedHash_Lookup(map, tag); // FUN_0046c1b0
    object obj = null;
    if (node != map.Sentinel)
        obj = node.Creator(); // node+0x0c, 0 args
    outObj = obj;
    if (obj == null)
        return 0xFFFFFFFFu;
    // this = obj+4; vfunc slot 1; arg = reader; return status
    return obj.SubobjectAt4.Unserialize(reader);
}
```

**Port traps to reject:**

- Passing tag into creator
- Using MapB getter
- Treating return as object pointer
- Calling insert API from this unit
- Assuming ECX=factory this
- Assuming fail returns 0

---

## 5. Verdict

**accept-with-gaps** — adversarial checks hold for ABI/CF/Peek/MapA/create/vfunc/fail. Remaining gaps are concrete object types and unowned map-op internals — not body fidelity.
