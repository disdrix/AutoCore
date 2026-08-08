# Review B (skeptical / adversarial): `aa_0051b350` ServerCreateFromPacket

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ9R-I) |
| **Counterpart** | `reviews/A_aa_0051b350_ServerCreateFromPacket.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + callees. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `unaff_EDI` is a real 4th map argument | **Falsified** — map call is thiscall + outIt + key; remap flag is **BL** (`XOR BL,BL` / `MOV BL,1`) |
| 2 | `FUN_00787d40(&local, n)` is a free function with no stream | **Falsified** — `__thiscall`; ECX = stream (EDI from stack arg0) |
| 3 | `param_1` is host and `param_2` is stream | **Falsified** — bytes: EDI=arg0 used as **stream** for unpack **and** passed into `vtbl+0x20`; host is **arg1** for `vtbl+8` only |
| 4 | COID lives at `piVar3[0x58]` as abstract index without byte meaning | **Partially** — dword index is correct **and** equals **+0x160** (global COID/TFID convention) |
| 5 | Success flag `\| 0x80` is same as AllocateNewObjectFromCbid `\| 0x10` | **Falsified** — different bit; do not merge flag semantics |
| 6 | Function is a skill residual cast helper | **Falsified** — create-from-packet factory; skill-adjacent address only |
| 7 | Decompiler void/undefined return | **Falsified** — returns object* in EAX (`MOV EAX,ESI` / null) |
| 8 | No SEH / always succeeds | **Falsified** — full SEH frame; multiple fail logs + cleanup |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stream/host arg order | **High** | Init host null / unpack wrong buffer |
| CBID -1 early out | **High** | Spurious factory |
| Remap map + node+0x10 | **High** | Wrong clonebase |
| COID stamp +0x160 before vtbl+0x20 | **High** | Identity desync |
| `+0x17c \|= 0x80` only if remapped | **High** | Flag pollution on non-remap creates |
| Product name ServerCreateFromPacket | **High** | Naming only if wrong |
| Call graph (xrefs empty) | **Low** | Miss integration points |
| Fail-path list walk exact types | **Medium** | Leak / double-free on port |

---

## 3. Cross-check critical traps

### 3.1 Map call (decompiler vs bytes)

Decompiler:

```c
Map_LowerBoundFindByIntKey((void *)(DAT_00b041fc + 4), &local_24, &local_28, unaff_EDI);
```

Bytes (mid-body):

```
MOV ESI, [DAT_00b041fc]
LEA EDX, [ESP+key]
PUSH EDX
LEA EAX, [ESP+outIt]
PUSH EAX
LEA ECX, [ESI+4]
XOR BL, BL
CALL Map_LowerBoundFindByIntKey
MOV ESI, [ESI+8]          ; end sentinel
CMP EAX/outIt, ESI
JE  no_remap
MOV ECX, [it+0x10]
MOV [key], ECX
MOV BL, 1
```

**Port rule:** ignore `unaff_EDI`; use boolean from iterator≠end.

### 3.2 Arg roles

| Formal | Role | Used by |
|---|---|---|
| stack0 | unpack stream* | `FUN_00787d40` ECX; `vtbl+0x20` 4th stack formal |
| stack1 | host* | `vtbl+8` 2nd formal (with cbid, 1) |

### 3.3 Must not port as AllocateNewObjectFromCbid

| | ServerCreateFromPacket | AllocateNewObjectFromCbid |
|---|---|---|
| Input | packet CBID+COID | cbid + optional template |
| Success flag | `+0x17c \|= 0x80` if remapped | `+0x17c \|= 0x10` always on success |
| COID | from packet + vtbl+0x20 | host counter / SetCoidIdentity path |

---

## 4. Surviving contract for AutoCore

```csharp
// Port of ServerCreateFromPacket (0x0051b350)
Object ServerCreateFromPacket(UnpackStream stream, object host)
{
    using var _ = Profiler.Enter("ServerCreateFromPacket");

    int cbid = stream.ReadInt32();
    if (cbid == -1) return null;

    long coid = stream.ReadInt64();

    bool remapped = false;
    if (GameData.TryRemapCbid(cbid, out int mapped)) { // map @ DAT_00b041fc+4, value node+0x10
        cbid = mapped;
        remapped = true;
    }

    var obj = CVOGReaction.GiveItemByCbid(cbid);
    if (obj == null) {
        Log(1, "Invalid CBID allocated: %d, coid : %I64d", cbid, coid);
        return null;
    }

    if (obj.InitFromCbid(cbid, host, 1) < 0) { // vtbl+8
        Log(1, "Invalid CBID initified: %d, coid : %I64d", cbid, coid);
        return null;
    }

    obj.CoidLo = (uint)coid;
    obj.CoidHi = (uint)(coid >> 32);
    obj.CoidValid = 1; // +0x168

    if (obj.InitFromCoid(obj.CoidLo, obj.CoidHi, 0, stream, 1) < 0) { // vtbl+0x20
        Log(1, "Invalid COID initified: %d, coid : %I64d (in ServerCreateFromPacket)", cbid, coid);
        obj.DestroyChildrenAndSelf(); // vtbl+0x2B0 walk + delete
        return null;
    }

    if (remapped) obj.Flags |= 0x80; // +0x17c
    return obj;
}
```

---

## 5. Open questions

1. Who calls this (Ghidra xref empty)?
2. Remap map product English / key domain (always CBID?).
3. Whether fail path must free the object itself beyond child list (vtbl+0x2B0 may include self — out of owned proof).
4. Server-side port: same create order vs authoritative COID assignment.

**Verdict:** **accept-with-gaps**
