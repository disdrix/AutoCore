# Function record: PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00416590` |
| **Canonical name** | `PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred` |
| **Ghidra name** | `FUN_00416590` |
| **Address** | `0x00416590`–`0x004165CF` exclusive (**63 B** / `0x3F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container shell (generic; elem stride **0x14**) |
| **Classification** | leaf |
| **Calling convention** | **ECX** = shell*; **`ret 0`** |
| **Completion status** | **Dual A/B sealed** — accept-with-gaps (WQ9I-J 2026-08-05) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00416590_PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred.md` |
| **Dual B** | `reviews/B_aa_00416590_PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred.md` |
| **Name confidence** | Inferred (structural; multi-caller generic util) |
| **Last reviewed** | `2026-08-05` (WQ9I-J) |

## Alias

- Ghidra: `FUN_00416590`
- Prior scaffold: partial raw/annotated/clean only
- Reject: mission/NDUI product alias from auto parent-seed; skill/tree domain

## Purpose

MSVC-style **default constructor** for a **0x14-byte** host that embeds a pointer-vector triad at `+8/+0xC/+0x10`:

1. SEH frame with `LAB_009bcfab` (EH state −1; no cleanup during body).
2. Zero dwords at `+0`, `+8`, `+0xC`, `+0x10`.
3. **Do not write `+4`**.
4. Return void via plain `C3`.

Element size sealed by `_eh_vector_constructor_iterator_(…, size=0x14, count=9, ctor=this, dtor=FUN_00417ee0)` inside audio UI ctor `FUN_00820830`. Four BSS statics at `0xd218e0 + n*0x14` also call this then register `_atexit`.

## Signature

```c
void PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred(
    /*ECX*/ uint32_t* self);
/* ret 0 */
```

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | none (leaf) |
| **Callers** | `FUN_00820830` DATA push for eh_vector; static inits `0x009bf3c5` / `0x009bf5f5` / `0x009bf615` / `0x009bf635` |
| **Peer dtor (not owned)** | `FUN_00417ee0` — free `+8` if non-null; zero triad |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00416590_FUN_00416590.md`
- Annotated: `docs/reconstruction/raw/aa_00416590_FUN_00416590.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/PtrVecShell0x14_DefaultCtor_ZeroSkip4_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00416590.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_00416590_FUN_00416590.md`
- Report: `docs/agents/task-dual-ab-00416590-004165f0-wq9ij-report.md`

## Confidence

| Claim | Level |
|---|---|
| Body + ret 0 + ECX this | **High** |
| Zero +0/+8/+0xC/+0x10; skip +4 | **High** |
| Elem size 0x14 (eh_vector + BSS) | **High** |
| Ptr-vector triad role at +8 | **High** (peer dtor/atexit) |
| Product demangle / +0,+4 English | **Inferred** / open |
| Runtime / bit-exact | **Open** |
