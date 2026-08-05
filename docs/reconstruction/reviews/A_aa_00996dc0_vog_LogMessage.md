# Review A (reconstruction fidelity): `aa_00996dc0` vog_LogMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_00996dc0` |
| **VA** | `0x00996dc0` |
| **Canonical name** | `vog_LogMessage` |
| **System** | `diagnostics` / errReport logging sink |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00996dc0_vog_LogMessage.md` |
| **Live tools** | Ghidra `decompile_function` + `read_memory` (+ callee light touch for return-3 residual). No `disassemble_bytes`. |
| **Program** | `autoassault.exe` only |
| **Verdict** | **accept-with-gaps** (this unit CF/ABI High; dispatcher `FUN_0076d1b0` residual) |

---

## 1. Purpose

Engine-wide **log / assert sink**. Call sites pass original `C:\vog\1_code\...` source paths (primary name-recovery ore in this stripped retail build). This unit:

1. Forwards `(sourceFile, line, message)` on the stack and **severity in EDI** into the real report dispatcher `FUN_0076d1b0` (`0x0076d1b0`).
2. If the dispatcher returns **exactly 3**, writes a one-shot crash report to `c:\VOGCRASH.txt`, `raise(SIGABRT=0x16)`, then **`ExitProcess(3)`** (no-return).
3. Otherwise restores callee-saved regs and returns.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Function record | `docs/reconstruction/functions/aa_00996dc0_vog_LogMessage.md` |
| Raw | `docs/reconstruction/raw/aa_00996dc0_vog_LogMessage.md` |
| Annotated | `docs/reconstruction/raw/aa_00996dc0_vog_LogMessage.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/vog_LogMessage.cpp` |

---

## 3. Seal: body (`read_memory` @ `0x00996dc0`)

Body range **`0x00996dc0`–`0x00996e32`** (`ret` / `C3`); padding `CC` after.

```
8b442404 538b5c2414 558b6c2410 578b7c2418
535550 e8d563ddff 83c40c 83f803 754c
56 68784ba100 6898d0a900 ff1590669c00
8bf0 83c408 85f6 741e
8b4c2414 53 57 55 51 685cd0a900 56 ff1568669c00
56 ff156c669c00 83c41c
6a16 ff1524649c00 83c404
6a03 ff15c4609c00
5e 5f 5d 5b c3
```

### Control flow (machine)

```
; cdecl entry; stack formals:
;   [esp+4]=sourceFile, [esp+8]=line, [esp+0xC]=severity, [esp+0x10]=message

mov  eax, [esp+4]          ; sourceFile
push ebx
mov  ebx, [esp+0x14]       ; message  (orig +0x10)
push ebp
mov  ebp, [esp+0x10]       ; line     (orig +0x08)
push edi
mov  edi, [esp+0x18]       ; severity (orig +0x0C)  → EDI for dispatcher ABI
push ebx                   ; arg3 message
push ebp                   ; arg2 line
push eax                   ; arg1 sourceFile
call FUN_0076d1b0          ; 0x0076d1b0  (cdecl; severity via EDI)
add  esp, 0x0C
cmp  eax, 3
jnz  epilogue              ; non-fatal: just return

; fatal path (dispatcher returned 3)
push esi
push "w"                   ; 0x00a14b78
push "c:\\VOGCRASH.txt"    ; 0x00a9d098
call [fopen IAT 0x009c6690]
mov  esi, eax
add  esp, 8
test esi, esi
jz   after_file
  fprintf(file,
    "errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n",
    sourceFile, line, severity, message)   ; strings @ 0x00a9d05c
  fclose(file)
after_file:
push 0x16                  ; SIGABRT
call [raise IAT 0x009c6424]
push 3
call [ExitProcess IAT 0x009c60c4]   ; does not return

epilogue:
pop regs; ret              ; plain cdecl ret (C3), no ret N
```

### ABI (this unit)

| Item | Machine | Conf |
|---|---|---|
| Convention | MSVC **cdecl**: 4 stack dwords; **`ret` (`C3`)** | **High** |
| `param_1` | `const char* sourceFile` | **High** (fprintf `%s` + call-site literals) |
| `param_2` | `int line` | **High** (fprintf `%d`) |
| `param_3` | `int severity` | **High** (fprintf `%d`; loaded into **EDI** for sink) |
| `param_4` | `const char* message` / detail | **High** (fprintf `%s` as `d:`) |
| Return | void (fatal path does not return) | **High** |
| Varargs in **this** body | **None** — no `va_list` / no extra stack walk | **High** |
| Plate `fmt, ...` | **Overstated for this unit** — message is a ready string at sealed call sites | **High** (this unit); dispatcher may format elsewhere |

### Callees (owned only as call edges)

| Target | Role |
|---|---|
| `FUN_0076d1b0` @ `0x0076d1b0` | Report / severity dispatcher; return **3** ⇒ abort |
| `fopen` / `fprintf` / `fclose` | Crash file `c:\VOGCRASH.txt` |
| `raise(0x16)` | `SIGABRT` |
| `ExitProcess(3)` | Terminate process exit code 3 |

### String constants (`read_memory`)

| VA | Content |
|---|---|
| `0x00a9d098` | `c:\VOGCRASH.txt` |
| `0x00a9d05c` | `errReport::Massive failure EH_Abort: F:%s l:%d s:%d d:%s\n` |
| `0x00a14b78` | `w` (fopen mode) |

### Body metrics (Ghidra signature meta)

- Body: `00996dc0`–`00996e32`
- ~42 instructions, 5 basic blocks, cyclomatic complexity **2**
- Call sites: **hundreds** (coverage inventory ~765 xrefs); sample includes graphics unlock assert, CloneBase, `corErrorHandler.cpp`

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| cdecl + 4 stack formals + plain `ret` | **High** | machine epilogue `C3` |
| Forwards file/line/message to `FUN_0076d1b0`; severity in **EDI** | **High** | this body + light callee entry `mov ebp,[edi*4+0x00afa2c0]` |
| Return value **3** ⇒ VOGCRASH + raise + ExitProcess(3) | **High** | machine |
| Non-3 ⇒ silent return (no local logging in this wrapper) | **High** | machine |
| Crash file path / EH_Abort format string | **High** | `read_memory` |
| `raise` arg `0x16` = SIGABRT | **High** | CRT convention |
| Clean ≡ raw control flow | **High** | scaffold match; param renames evidence-only |
| Full semantics of non-3 return codes inside `FUN_0076d1b0` | **Open / residual** | callee not owned |
| Whether any call sites use true printf varargs into this entry | **Tentative** | sealed sites use 4 fixed args; plate overstated |
| Bit-for-bit / runtime / differential | **Open** | deferred |

---

## 5. Control flow checklist: clean ≡ raw ≡ machine

| Stage | Match |
|---|---|
| Load 4 formals; EDI=severity | **Yes** |
| `FUN_0076d1b0(file, line, message)` + severity via EDI | **Yes** |
| `if (result == 3)` fatal branch | **Yes** |
| fopen / optional fprintf+fclose / raise / ExitProcess | **Yes** |
| Else return | **Yes** |
| No local non-fatal log path in this wrapper | **Yes** |

---

## 6. Gaps / open

1. **`FUN_0076d1b0` full policy** (handler table `@ 0x00afa2c0`, when handlers vote severity, why return 3) — sibling unit.
2. **Other log entry points** that may share the dispatcher (not this VA).
3. Whether production ever sets severity **> 4** (callee forces 3) vs handlers returning 3.
4. Runtime / bit-exact harness not run.

**Verdict:** **accept-with-gaps**
