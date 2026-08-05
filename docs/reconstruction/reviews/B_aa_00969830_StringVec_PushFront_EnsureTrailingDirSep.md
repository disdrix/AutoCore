# Review B (skeptical / adversarial): `aa_00969830` StringVec_PushFront_EnsureTrailingDirSep

| Field | Value |
|---|---|
| **Stable ID** | `aa_00969830` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-E) |
| **Counterpart** | `reviews/A_aa_00969830_StringVec_PushFront_EnsureTrailingDirSep.md` |
| **Scratch** | `tmp/a_00969830.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Ghidra `unaff_ESI` means no this | **Falsified** — callers `mov esi,[DAT_00d1f1fc]`; body `mov ecx,esi` for insert |
| 2 | Push/back append | **Falsified** — insert pos = `*(ESI+4)` = begin |
| 3 | Overwrites existing element without grow | **Falsified** — `FUN_00430310` → `FUN_004306b0` insert-N path |
| 4 | Always appends `/` | **Falsified** — `FUN_009694e0` skips when empty or last is `: / \\` |
| 5 | Uses `DAT_00d1f058` as the vector | **Falsified** — call sites load `DAT_00d1f1fc`; host+0xb4 is separate path field |
| 6 | cdecl void(path) only | **Falsified** — `ret 4` + ESI this; stack one formal |
| 7 | Product name `Named_CalleeOf_Named_assManager_*` is sealed | **Rejected** — scaffold plate; structural name used |
| 8 | No SEH | **Falsified** — `LAB_009acaf6` frame + local string EH states |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI = StringVecShell* | **High** | Wrong container / crash |
| Front insert | **High** | Search-path priority inverted |
| Trailing-sep normalize | **High** (via helper decompile) | Path join bugs |
| Nested insert grow details | **Med** | Port may miss capacity math if reimplemented |
| Product list English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// FUN_00969830:
// SEH; local basic_string
call FUN_009694e0(&local, path)
mov  eax, [esi+4]          ; begin
// push local, begin, &out; mov ecx,esi
call FUN_00430310          ; insert at begin
~basic_string(local)
ret  4

// FUN_007b75b0 call sites:
mov  esi, [DAT_00d1f1fc]
push path
call FUN_00969830
```

Decompile ≡ hex for stage order. Insert-at-begin sealed by pos argument = begin.  
Release dual erases from same `*DAT_00d1f1fc` with 0x1c stride — consistent.

---

## 4. Surviving contract for AutoCore

```
// Port as path-list push_front with normalize:
void StringVec_PushFront_EnsureTrailingDirSep(StringVecShell* v, const std::string& path) {
  std::string local = EnsureTrailingDirSep(path); // FUN_009694e0
  v->insert(v->begin(), local);                   // FUN_00430310/306b0
}
// Callers must pass *DAT_00d1f1fc in ESI (or equivalent this).
// Do not confuse with host+0xb4 string assign in AssManager init.
```

---

## 5. Verdict

Adversarial pass confirms A on ESI ABI, front insert, and normalize stage. Nested helper product plates remain open → **accept-with-gaps**.
