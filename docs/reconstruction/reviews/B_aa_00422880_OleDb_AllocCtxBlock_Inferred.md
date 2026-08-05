# Review B (skeptical / adversarial): `aa_00422880` OleDb_AllocCtxBlock_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00422880` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-B) |
| **Counterpart** | `reviews/A_aa_00422880_OleDb_AllocCtxBlock_Inferred.md` |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Function is truly `void` with no return contract | **Falsified** — tail builds HRESULT in EAX; caller checks `hr < 0` |
| 2 | Alloc size is `count` bytes (not `count*8`) | **Falsified** — three `add eax,eax` → `*8` |
| 3 | `FUN_004228d1` is an independent product API with its own formals | **Falsified as product split** — SEH continuation; shares ESI/EBP from parent |
| 4 | `__thiscall` / ECX-this | **Falsified** — both formals from `[ebp+8]` / `[ebp+0xC]`; `ret 8` |
| 5 | Caller always passes arbitrary column count | **Falsified at sole site** — only `push 1` observed |
| 6 | Failure path leaves stale non-null `*param_1` | **Falsified** — zeroed before alloc; OOM leaves null → E_OUTOFMEMORY |
| 7 | Scaffold “unknown system” is final | **Falsified as final** — sole caller is sealed OleDb binding builder |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| HRESULT / OOM contract | **High** | Caller skips fail cleanup |
| `count*8` stride | **High** | Under-alloc / heap smash on port |
| `ret 8` | **High** | Stack imbalance |
| Product buffer element type | Medium | Naming / layout docs only |
| Non-OleDb reuse | Low–Medium | Over-narrow system tag |

---

## 3. Cross-check against raw + bytes

```
push 1; push ebx; call 00422880   ; sole site 00421604
  → [ebx+4]=1; [ebx]=0; [ebx]=new[](8)
  → EAX = (ptr!=0)?0:0x8007000E; ret 8
post-success caller: *(*(ebx)+4) = 1   ; flag inside 8-byte block
```

Clean must **not** invent CreateAccessor, column loops, or row-size math — those live in `0042139b` / `00421677`.

Do **not** treat Ghidra body end `004228c7` as missing HRESULT; the `jmp` to `004228d1` is the status epilogue.

---

## 4. Surviving contract for AutoCore

```csharp
// Port shape (OLE DB / accessor ctx gate)
int OleDb_AllocCtxBlock(ref CtxBlock b, int count)
{
    b.Count = count;
    b.Buf = Alloc(count * 8); // may null
    return b.Buf != null ? 0 : unchecked((int)0x8007000E);
}
// Caller: if (hr < 0) cleanup; else mark gate flag on *Buf
```

---

## 5. Open questions

1. Whether AutoCore server needs this path at all (client OLE DB residual).
2. Exact 8-byte record layout written after success (`+4` byte flag observed).

**Verdict:** **accept**
