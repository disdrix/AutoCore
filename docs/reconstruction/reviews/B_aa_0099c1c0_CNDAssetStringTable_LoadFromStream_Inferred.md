# Review B (skeptical / adversarial): `aa_0099c1c0` CNDAssetStringTable_LoadFromStream_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099c1c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (W37-I) |
| **Counterpart** | `reviews/A_aa_0099c1c0_CNDAssetStringTable_LoadFromStream_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` on **own VA** (+ caller + W34-J/W31-F context). No ledger edits. No `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Is `CNDAssetStringTable::Unserialize` itself | Body builds host + calls `0099bba0`; no plate string here | **Falsified** — **wrapper / loader** |
| 2 | ECX-thiscall on table object | Stream on stack; `RET 4`; no durable this | **Falsified** — stack stream ABI |
| 3 | Always succeeds | Null stream returns 0; else forwards Unserialize AL | **Clarify** — null hard-false; else callee AL |
| 4 | `FUN_00989ef0` is thiscall ECX=object | W31-F + bytes: **EDI=object**, **ECX=field10** | **Falsified** decompiler label; sealed EDI ABI |
| 5 | `operator_delete` never returns | Epilogue after delete path present | **Falsified** Ghidra warning — ignore noreturn |
| 6 | Multiple retail callers | Xrefs: only `FUN_004d73c0` | **Clarify** — **sole** caller |
| 7 | Persists host globally | Local stack host + dtor before return | **Falsified** — temporary |
| 8 | Configure uses 0x10000 like other site | Bytes `B9 00 40 00 00` = **0x4000**; push **1** | **Falsified** — site-specific constants |
| 9 | Implements serialize twin | Only calls Unserialize | **Falsified** |
| 10 | Name requires product demangle of wrapper | Wrapper English Inferred; Unserialize plate is product | **OK** — `_Inferred` appropriate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null stream → AL=0 | **High** | Ports crash on null |
| RET 4 / stack stream | **High** | Stack imbalance |
| Calls Unserialize with 3 args | **High** | Wrong host/stream wiring |
| Configure EDI + ECX=0x4000 + flag1 | **High** | Mis-size internal tables |
| Temporary host only | **High** | Leak / use-after-free if assumed global |
| Host field map | **Medium/Low** | Wrong member offsets if over-specified |
| Stage gate on caller | **Medium** | Doc only for this unit |

---

## 3. Cross-check against raw / bytes

```
raw decompile:
  if !stream: return 0
  ctor cache; vtbl; zero vec
  configure(1)
  ok = Unserialize(&host, scratch, stream)
  if vec: delete path
  dtor; return ok

bytes refine:
  MOV EBX, [stream]; test null
  MOV ECX,0x4000; PUSH 1; LEA EDI,cache; CALL 00989ef0
  PUSH stream; LEA scratch; LEA host; CALL 0099bba0
  ADD ESP,0xA8; RET 4
```

Clean must **not** invent:

- Inlined string/pyramid parse (that is `0099bba0`)
- Global singleton host
- ECX-this on this function
- Configure constants from the other `00989ef0` site (`0x10000`/`0x40000`)
- Treating Ghidra noreturn delete as terminal

---

## 4. Surviving contract for AutoCore

```csharp
// Behavior-exact port of 0x0099c1c0
static bool CNDAssetStringTable_LoadFromStream(StreamReader stream)
{
    if (stream == null) return false;

    var host = new TempCndStringTableHost(); // vtbl 00a983b4 + ResourceCache-family body
    ResourceCache_SetField10AndConfigure(host.Cache, field10: 0x4000, flag: 1);
    bool ok = CNDAssetStringTable_Unserialize(host, scratch: null, stream);
    host.DisposeVectorIfAny();
    host.Dispose();
    return ok;
}
```

---

## 5. Verdict

**accept-with-gaps** — adversarial review confirms wrapper-not-parse role, RET-4 ABI, null gate, and configure constants; host layout English remains the main gap.
