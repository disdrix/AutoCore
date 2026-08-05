# Review B (skeptical / adversarial): `aa_004449b0` Sto_AbstractUnserializationFactory_InsertCreator_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004449b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W36-A) |
| **Counterpart** | `reviews/A_aa_004449b0_Sto_AbstractUnserializationFactory_InsertCreator_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ wrapper caller bytes + MapA context). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Function is MapA **GetInstance** | Body has insert/log/creator store; calls GetInstance thrice | **Falsified** — insert worker; getter is `0x00438c40` |
| 2 | ECX-thiscall on factory object | No ECX this; map from GetInstance; plain RET | **Falsified** — **cdecl** + EBX register arg |
| 3 | Creator is stack arg1 | Wrappers only `PUSH tag`; `MOV EBX,imm`; store `MOV [EAX+0xC],EBX` | **Falsified** — **EBX** is creator |
| 4 | Duplicate path skips creator update | Store runs after both insert and existing-node paths | **Falsified** — always rebinds `+0xc` |
| 5 | Uses MapB `FUN_00438ca0` | All GetInstance relocs → `0x00438c40` | **Falsified** — Map A only |
| 6 | Is the whole AbstractUnserializationFactory class | Single insert helper; no vtable/object | **Clarify** — map insert helper, not class ctor |
| 7 | Logs and aborts without insert | Log is non-fatal; second lookup + possible insert + always store | **Falsified** — log-only side effect |
| 8 | Scaffold Palantir callee-of name is product role | Strings are arda2/storage; callers are FourCC wrappers | **Over-narrow** — reject scaffold |
| 9 | `FUN_0046bf90` always runs | `JNE` skips insert when node ≠ sentinel | **Clarify** — insert on miss only |
| 10 | Decompiler missing args invalidate seal | Bytes reconstruct ESI/EDI/ECX/EAX map-op ABI | **No** — CF sealed; map ops unowned detail |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Tag stack + EBX creator ABI | **High** | Ports pass creator on stack → wrong registration |
| Always write `node+0xc` | **High** | Duplicate path leaves stale creator |
| Map A only | **High** | Cross-wire MapB registrations |
| Non-fatal duplicate log | **High** | Ports treat as hard error / skip update |
| NestedHash find/insert callees | **High** role / **Medium** internals | Wrong node size if inventing allocator |
| FourCC domain English (GPCE/GSKN/GMPH) | **Medium** | Doc only |
| Thread-safe map | **None claimed** | Races if multi-thread register |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  mapA(); sentinel=*(map+8)
  lookup; if found: log duplicate
  lookup; if miss: insert {tag,0}
  *(node+0xc) = EBX

bytes:
  CALL 00438c40; MOV EDI,[EAX+8]
  CALL 00438c40; CALL 0046c1b0; CMP node,EDI; JE skip; vog_LogMessage
  CALL 00438c40; CALL 0046c1b0; CMP node,[ESI+8]; JNE have
  CALL 0046bf90; MOV EAX,[EAX]
have: MOV [EAX+0xC], EBX; RET
```

Clean must **not** invent:

- PeekChunkTag / unserialize vfunc (those are `FUN_00437b00`)
- MapB GetInstance
- Hard-fail return codes (void RET)
- Creator as second stack parameter
- Skipping `+0xc` write on duplicates

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x004449b0
// tag on stack; creator in a register corresponding to EBX
static void Sto_AbstractUnserializationFactory_InsertCreator(uint tag, CreatorFn creator)
{
    var map = Sto_UnserialFactoryMapA_GetInstance(); // FUN_00438c40
    var sentinel = map.Sentinel; // *(map+8)
    var node = NestedHash_Lookup(map, tag); // FUN_0046c1b0
    if (node != sentinel)
        Log("..\\arda2/storage/stoAbstractUnserializationFactory.h", 0x24, 2,
            "Inserting duplicate creator tag to factory");
    node = NestedHash_Lookup(map, tag);
    if (node == map.Sentinel)
        node = NestedHash_Insert(map, tag, 0); // FUN_0046bf90
    node.CreatorAt0x0C = creator; // always
}
```

**Port traps to reject:**

- Using MapB getter `0x00438ca0`
- Treating duplicate as exception without rebind
- ECX-this factory object
- Omitting EBX/register creator channel
- Folding insert into GetInstance

---

## 5. Verdict

**accept-with-gaps** — adversarial checks hold for ABI/CF/strings/MapA/creator store. Remaining gaps are unowned map-op internals and product tag-domain English — not body fidelity.
