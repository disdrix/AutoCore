# Review B (skeptical / adversarial): `aa_00418700` StdList_BuyNode_Dword_Seh

| Field | Value |
|---|---|
| **Stable ID** | `aa_00418700` |
| **VA** | `0x00418700` |
| **Canonical name** | `StdList_BuyNode_Dword_Seh` |
| **Review date** | `2026-08-05` (MEGA-081 dual) |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_00418700_StdList_BuyNode_Dword_Seh.md` |
| **Live tools** | Independent `decompile_function` + `disassemble_function` + `read_memory` + analyze/xrefs/callers |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is **DebugListMissionsStatus**-specific / reward-list only | **Falsified** — **61** CALL xrefs across inventory, character serialize, UI, mission helpers |
| 2 | Tree / map **Buynode** (isnil family) | **Falsified** — node size **0xC**, no isnil/color; list Incsize peer uses `"list<T> too long"` |
| 3 | **thiscall** / ECX=this | **Falsified** — args at `[EBP+8/+C/+10]`; **`RET 0xC`**; no ECX this |
| 4 | True **void** (no return) | **Falsified** — call sites `MOV reg,EAX` after CALL (`00402d2c`, `0040410c`, `00517dd0`, …) |
| 5 | Value stored by **pointer** (not dereference) | **Falsified** — `MOV EDX,[ECX]; MOV [EAX+8],EDX` |
| 6 | Body also Incsize / relinks list | **Falsified** — only new+fill; wrappers call `FUN_00404840` / `FUN_00418790` then write links |
| 7 | Same binary as `006759b0` (merge units) | **Falsified** — different VA; this has full SEH frame (122 B vs 39 B) |
| 8 | freelist / slab reuse | **Falsified** — plain `operator_new(0xC)` |
| 9 | Runtime Confirmed | **Fails** — open (no Launcher) |

---

## 2. Decisive machine dataflow

```text
PUSH 0xC
CALL operator_new          ; EAX = raw
TEST EAX,EAX / JZ fail
MOV ECX, [EBP+8]  / MOV [EAX], ECX       ; link0
MOV EDX, [EBP+0xC]/ MOV [EAX+4], EDX    ; link1
MOV ECX, [EBP+0x10]/ MOV EDX, [ECX]
MOV [EAX+8], EDX                         ; *pValue
; EAX still node*
RET 0xC
```

Call-site (wrapper `FUN_00402d10` @ `0x00402d24`):

```text
CALL 0x00418700
PUSH 1
MOV  ECX, ESI          ; list this for Incsize
MOV  EBX, EAX          ; capture node*
CALL FUN_00404840
MOV  [EDI+4], EBX
MOV  EDX, [EBX+4]
MOV  [EDX], EBX
RET  4
```

A ≡ B on live decompile + body hex + xrefs + call-site EAX capture.

---

## 3. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| new(0xC)+3 dword fill CF | **High** | wrong allocator port |
| `__stdcall` RET 0xC; EAX return | **High** | stack smash / lost node |
| List (not tree) helper | **High** | wrong container family |
| SEH vs non-SEH twin split | **High** | wrong VA merge |
| Product T English | Medium | naming only |
| Runtime | open | — |

---

## 4. Surviving contract for AutoCore

```csharp
// SEH-framed list _Buynode for dword payload (node size 0xC)
// Twin without SEH: StdList_BuyNode_Dword @ 0x006759b0
IntPtr BuyNodeDwordSeh(IntPtr link0, IntPtr link1, ref uint value)
{
    // operator_new(0xC); if null return 0
    // *(node+0)=link0; *(node+4)=link1; *(node+8)=value
    // return node;  // stdcall ret 12
}
// Callers: Incsize + head[+4]=node + *node[+4]=node. Do not size++ here.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/caller roles/twin split. Parent-seed and reward-only claims falsified. Residual product English + runtime → documented gaps, not CF holes.

**Verdict:** **accept**
