# Review B (skeptical / adversarial): `aa_00489822` operator_delete

| Field | Value |
|---|---|
| **Stable ID** | `aa_00489822` |
| **VA** | `0x00489822` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (R10-001 OWN dual) |
| **Counterpart** | `reviews/A_aa_00489822_operator_delete.md` |
| **System** | shared CRT import thunk (`client::crt`) |
| **Verdict** | **accept** |

**Tools:** same live Ghidra set as A. **No** `disassemble_bytes`. No Launcher. No runtime Confirmed.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Ghidra: subroutine does not return | Project-wide false noreturn on `operator_delete`; CALL sites continue after `ADD ESP,4` | **Falsified** as CF |
| 2 | Decompiler recursive self-call is real body | Bytes = `FF 25 …` IAT JMP; no CALL instruction in body | **Falsified** |
| 3 | "Could not recover jumptable" implies switch | Classic MSVC `jmp [iat]` misread by decompiler | **Falsified** |
| 4 | Inventory-transfer product free helper | 5045 callers across FUN+Unwind; CRT name; adjacent import island | **Falsified** as product identity |
| 5 | Same as `operator_delete[]` @ `0x0048981c` | Distinct IAT slots (`009C6694` vs `009C6698`); array vs scalar | **Falsified** as merge |
| 6 | Same as `free` @ `0x004898f4` | Different import thunk VA/IAT; C `free` vs C++ `operator delete` | **Falsified** as merge |
| 7 | thiscall / ECX block pointer | cdecl stack formal; thunk ignores ECX | **Falsified** |
| 8 | In-image heap manager (custom free) | 6-byte JMP only; implementation behind IAT | **Falsified** |
| 9 | Name needs `_Inferred` | Ghidra custom CRT symbol + import pattern sealed | **Falsified** |
| 10 | Runtime Confirmed required for accept | Dual seal is static CF/ABI/name; terminal remains false | **Survives as process** — not a reject |

---

## 2. Live ≡ raw ≡ bytes

Decompiler (artifact):

```c
void __cdecl operator_delete(void *param_1)
{
  /* WARNING: jumptable / noreturn / treating indirect jump as call */
  operator_delete(param_1);
  return;
}
```

`read_memory` + function body range:

```text
00489822  FF 25 94 66 9C 00    JMP dword ptr [0x009C6694]
```

Annotated/clean express IAT tail transfer. **Match** on sealed machine CF; decompiler narrative discarded.

---

## 3. ABI adversarial check

| Probe | Observation |
|---|---|
| Param storage | `Stack[0x4]:4` void* — cdecl |
| CALL sites | `PUSH p; CALL 00489822; ADD ESP,4` (list destroy, scalar dtors, SEH Unwind) |
| Unwind volume | ~2568 Unwind callers — classic CRT free from SEH cleanup |
| Sibling island | `0048981c` delete[], `00489822` delete, then more `FF 25` imports |
| IAT xref | only **INDIRECTION** from this thunk to `009C6694` |

---

## 4. Surviving contract

```text
// Image VA 0x00489822
// JMP [0x009C6694]  → CRT scalar operator delete
// void __cdecl operator_delete(void *block);
// returns; not noreturn; not inventory-specific
```

**Not gaps for reject:** control flow, cdecl ABI, CRT name, thunk classification.

**Open (non-blocking):** CRT module/export identity behind IAT; runtime / bit-exact of free internals; terminal Confirmed.

---

## 5. Verdict

Path B does **not** force reject or gaps that undermine the unit. Noreturn / jumptable / inventory-product / merge claims fail hard. Static dual of this import thunk is complete.

**Verdict:** **accept**.
