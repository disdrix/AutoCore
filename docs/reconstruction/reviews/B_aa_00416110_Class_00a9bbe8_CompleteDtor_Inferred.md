# Review B (skeptical / adversarial): `aa_00416110` Class_00a9bbe8_CompleteDtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416110` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9I-G) |
| **Counterpart** | `reviews/A_aa_00416110_Class_00a9bbe8_CompleteDtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` + `disassemble_function` + callers/xrefs. **No** `disassemble_bytes`.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | Decompiler `void FUN(param_1)` with plain store is full story | **Partially true** — CF is store-only, but **SEH + stack ABI + ret 4** are real in bytes and required for ports |
| 2 | This is **thiscall** ECX=this | **Falsified** — body loads stack `[esp+0x10]`; caller `push esi` |
| 3 | Same type / method as transform assign `00416160` | **Falsified** — vptr class vs flag-gated matrix POD; only VA-neighborhood related |
| 4 | Dtor frees heap members | **Falsified** — leaf; sole side effect is vptr write |
| 5 | CxImage class (string after vtable in .rdata) | **Falsified as proof** — string is adjacent data packing, not RTTI for this type; no CxImage evidence in body/callers |
| 6 | Scaffold domain “unknown” blocks seal | **Falsified as blocker** — role sealed without product English |
| 7 | Runtime Confirmed | **Not claimed** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Vptr install only | **High** | Wrong teardown |
| Stack / ret 4 ABI | **High** | Corrupt stack at call sites |
| Sole caller sd-dtor path | **High** | Missed delete flag path |
| Product English | Low | Naming only |
| Runtime | Open | — |

---

## 3. Cross-check against raw + bytes

```
mov eax, fs:[0]
push -1
push 0x009bc0a8
push eax
mov fs:[0], esp
mov [esp+8], -1
mov eax, [esp+0x10]     ; obj*
mov ecx, [esp]          ; prior SEH
mov dword ptr [eax], 0x00a9bbe8
mov fs:[0], ecx
add esp, 0xc
ret 4
```

Caller `FUN_004160f0`:
```
mov esi, ecx
push esi
call 00416110
test [esp+8], 1
jz skip
push esi
call operator_delete
```

Do **not** port as ECX thiscall. Do **not** merge with `00416160`.

---

## 4. Surviving contract for AutoCore

```csharp
// void Class_00a9bbe8_CompleteDtor(IntPtr obj)  // stack arg, ret 4
// *obj = vftable_00a9bbe8;
// no free of obj (scalar-deleting wrapper owns delete)
```

Pair with `FUN_004160f0` scalar-deleting and ctor `FUN_0078bc20` when dualed.

---

## 5. Verdict

**accept-with-gaps** — adversarial checks confirm stack-arg complete dtor with pure vptr install. Residual: product name, virtual dtor dual, runtime. Not reject.
