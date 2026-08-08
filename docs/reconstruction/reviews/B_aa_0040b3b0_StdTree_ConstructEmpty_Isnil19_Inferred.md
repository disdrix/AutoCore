# Review B (skeptical / adversarial): `aa_0040b3b0` StdTree_ConstructEmpty_Isnil19_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040b3b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R13-017) |
| **Counterpart** | `reviews/A_aa_0040b3b0_StdTree_ConstructEmpty_Isnil19_Inferred.md` |
| **Dual start** | 2686 |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` (no `disassemble_bytes`).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is MissionTracker product method English | **Falsified** — generic StdTree empty shell; MissionTracker only hosts stack-local temp |
| 2 | Ghidra `undefined FUN_0040b3b0(void)` is full ABI | **Falsified** — stack shell* + `ret 4` + EAX=shell* |
| 3 | Full `_Buyheadnode` including alloc lives entirely here | **Falsified** — alloc is residual callee `0040bfc0`; this only installs |
| 4 | isnil29 / node 0x30 family | **Falsified** — isnil store @+0x19; buyhead size 0x1c |
| 5 | isnil31 / node 0x38 family (`00405f20`) | **Falsified** — different isnil offset + buyhead size |
| 6 | isnil21 / isnil2d families | **Falsified** — opcodes `C6 40 19 01` seal **+0x19** |
| 7 | thiscall ECX=this | **Falsified** — stdcall stack arg; `MOV ESI,[ESP+0x14]`; RET 0x4 |
| 8 | Clears value payload / freelist recycle | **Falsified** — only head links + isnil1 + size0 |
| 9 | Multi-caller / shared inventory UI entry | **Falsified** — sole xref from `0092b2a0` @ `0092b319` |
| 10 | Same body as siblings `0040b440`/`0040b890`/`0040bc10` | **Falsified as identity** — sibling residual helpers under same parent; different VAs/roles (not dualled here) |
| 11 | Runtime Confirmed | **Falsified** — no Launcher; terminal false |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| isnil@+0x19 install | **High** | wrong tree family |
| self-link + size0 | **High** | empty-tree invariant break |
| RET 0x4 stdcall | **High** | stack imbalance |
| Sole MissionTracker stack-local caller | **High** | mis-scope only |
| Node 0x1c via residual buyhead | **High** | alloc size mismatch |
| Product English | Medium | naming only |
| Key/value type of temp map | Low–Med | map identity only |

---

## 3. Cross-check against raw + bytes

```
SEH; mov esi, [esp+0x14]   ; shell*
call 0040bfc0              ; buyhead 0x1c → eax
mov [esi+4], eax           ; _Myhead
mov byte [eax+0x19], 1     ; isnil head
mov [eax+4], eax           ; parent=self
mov [eax], eax             ; left=self
mov [eax+8], eax           ; right=self
mov [esi+8], 0             ; size
mov eax, esi; ret 0x4
```

Clean must **not** invent MissionTracker domain semantics, freelist, isnil29/31 ConstructEmpty merge, thiscall, or Runtime Confirmed.

---

## 4. Surviving contract for AutoCore

```csharp
// Empty isnil19 tree shell construct
TreeShell ConstructEmpty_Isnil19(TreeShell shell)
{
    var head = BuyHeadNode_Isnil19_Size0x1c(); // residual 0040bfc0
    shell.Myhead = head;
    head.IsNil = true; // +0x19
    head.Left = head.Parent = head.Right = head;
    shell.Mysize = 0;
    return shell;
}
```

Port must keep **isnil@+0x19** and pair with **0x1c** buyhead — do not fold into isnil21/29/2d/31 empty construct. ABI: **stdcall** + **ret 4**.

---

## 5. Open questions

1. English type of stack-local map under MissionTracker secondary fill.  
2. Dual of residual buyhead `0040bfc0` and sibling map helpers under parent.  
3. Runtime / bit-exact.

**Verdict:** **accept-with-gaps**
