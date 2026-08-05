# Review B (skeptical / adversarial): `aa_00421362` OleDb_AllocBindingsBuf_EnterBuild_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00421362` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W24-F) |
| **Counterpart** | `reviews/A_aa_00421362_OleDb_AllocBindingsBuf_EnterBuild_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role). No `disassemble_bytes`. Own VA `0x00421362` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Standalone `__cdecl` with own prologue | body uses unaff_EBP/EBX; no `push ebp` | **Falsified** — **SEH-split fragment** |
| 2 | Calls `FUN_0042139b` then returns | bytes `EB 09` jmp | **Falsified as call** — **tail-join** |
| 3 | Always succeeds / void return | fail path E_OUTOFMEMORY + Release | **Falsified** — **HRESULT** |
| 4 | Allocates binding records (stride 0x34) here | size is plain `[ebx+0xc]`; parent does `*0x34` | **Falsified size role** — this unit is **colCount-sized** aux into +0x10 |
| 5 | Own `ret 4` on success | success never returns locally | **Falsified** — success leaves via jmp |
| 6 | EBX not required | loads `[ebx+0xc]/[ebx+0x10]` | **Falsified** — **EBX=ctx** |
| 7 | Scaffold "unknown system" is final | parent QI path + sibling OleDb duals | **Falsified** — **OLE DB setup chain** |
| 8 | Clean invents proven PDB name | no strings in body | **Open English** — `_Inferred` required |
| 9 | Three-rep diverges (raw vs live vs bytes) | live ≡ raw ≡ arm bytes | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Shared-frame fragment + SEH 0/4/−1 | **High** | wrong exception unwind |
| Null temp → E_OUTOFMEMORY | **High** | miss OOM path |
| `new[](+0xc)→+0x10` then jmp build | **High** | sibling null-check wrong |
| Product type English | **Inferred** | doc-only mislabel |
| Runtime / bit-exact | **Open** | shipping image |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  SEH=0
  if [ebp-0x1c]==0: SEH=-1; Release; return 0x8007000E
  SEH=4; [ebx+0x10]=new[]([ebx+0xc]); "call"/join FUN_0042139b

bytes:
  pre: 8B 5D 08
  entry: 83 7D E4 00 / C7 45 FC 00… / 75 0E
  fail: C7 45 FC FF… / EB 40
  ok: C6 45 FC 04 / 8B 43 0C / push / call new[] / 89 43 10 / EB 09
```

Decompiler "call FUN_0042139b; return" is **surface** — machine is **jmp**. Port must not invent a nested stack frame for the build.

**No conflict** on owned CF. Product symbol open.

---

## 4. Surviving contract for AutoCore

```csharp
// OleDb_AllocBindingsBuf_EnterBuild @ 0x00421362
// retail: shared EBP/SEH; EBX=ctx; success JMP 0x0042139b; fail HRESULT ret 4

int AllocBindingsBuf_EnterBuild(ctx, tempBindings)
{
  // if tempBindings==null → Release + E_OUTOFMEMORY
  // else ctx.auxOrStatus = new byte[ctx.colCount]; fall into BuildBindings
}
```

Port rules:

- Do **not** treat as a portable standalone function with its own ret on success.
- Keep **jmp-into-build** semantics (or inline as one SEH function with parent).
- Do not allocate `colCount*0x34` here — parent already did that for temps.
- Sibling `0042139b` **null-checks** `ctx+0x10` after this alloc (OOM if new[] failed).

---

## 5. Open questions

1. PDB / product name for this fragment and ctx type.
2. Whether merge of `00421362`+`0042139b`+`00421677` is desirable in Ghidra.
3. Live OOM / HRESULT under real provider.

**Verdict:** **accept-with-gaps**
