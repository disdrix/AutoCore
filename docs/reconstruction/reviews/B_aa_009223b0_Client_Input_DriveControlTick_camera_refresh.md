# Review B refresh: camera look-offset (skeptical)

| Field | Value |
|---|---|
| **Stable ID** | `aa_009223b0` |
| **Counterpart** | A camera refresh |
| **Scope** | Camera residual only — **not** full-function re-dual; **not** soft-steer dual body |
| **Evidence pass** | Live Ghidra re-decompile `0x009223b0` + `read_memory` (2026-07-29 strengthen) |
| **Verdict** | **accept-with-gaps** (structural locals-vs-steer **High**; UF-003 not fully closed) |

## Challenges

| Challenge | Outcome |
|---|---|
| Are `local_d*` really the steer axis? | **Rejected.** Steer is only `SetSteerInput` → `+0x618`. Locals never written to entity drive slots (`+0x614/+0x618/+0x61c`). Live decompile reconfirm. |
| Could `FUN_0091a5f0` secretly write `+0x618`? | **Unproven either way on callee internals** — but DCT call sites pass look scale + look vector pointer only; steer path never flows through that call. Separation at DCT layer holds without needing full callee dual. |
| Does `+0x101` suppress look? | **No** for local math — only axis setters gated. Hard-R example: look `local_d4`/vector updates run even when setter skipped. |
| Is “soft 0.2” the soft-steer band? | **No.** Soft steer is ±**0.5** → `+0x618` (UF-006). Soft look is ±**0.2** → `local_d4`. Distinct DAT / distinct sink. |
| Same bind → same semantic channel? | **Rejected as merge.** One flag can fire both effects; independence is by storage/gate/consumer, not by exclusive binds. |
| Is SECTION 15 “the camera system”? | **Partial** — epilogue projects into world slots; main look apply is `FUN_0091a5f0` earlier. Do not overclaim one SECTION owns all camera. |
| SECTION 3 analog: both paths at once? | **No (CF High).** Drive arm (`vehicle && +0x101==0`) uses setters; else arm uses look + vtbl `+0x44c` only. |
| Constant table complete? | **Normal-mode hard/soft sealed** (re-`read_memory`). Combat/special tables still multi-branch; not a full look-system seal. |
| Full function dual already 2026-07-23 + soft refresh | This refresh **adds** camera locals-vs-steer evidence only; soft dual body untouched. |

## Must not claim

- Semantic yaw/pitch/roll labels for `local_d0..c4` without further RE.
- That camera residual closes UF-003 entirely (skills / airborne / mode-table names remain).
- That look constants are “steering soft band” (soft ±0.5 is **steer axis**, separate from `local_d4` 0.03/0.2 look steps).
- Bit-exact camera product behavior or FOV naming for `local_d4`.
- That SECTION 15 writes depend on `local_d*` values without tracing through `FUN_0075c340` / globals (epilogue CF High as camera slots; data provenance partial).

## Survives attack

1. Separation: steer axis vs look locals — storage + gate + value domain + consumer (**High**).
2. Interleave in SECTION 7 without contaminating `+0x618` (**High**); bind-site matrix in A holds under live decompile.
3. Image floats for primary look steps 0.03 / 0.2 / 5 / 11 and alt 0.004 / −5 / 1.5 (**High**).
4. SECTION 3 camera-only analog branch when vehicle missing / `+0x101!=0` (**High** CF).
5. Push (SECTION 14) and steer clear path do not move look math into drive slots (**High**).

## Residual open (B keeps pressure)

| Open item | Why still open |
|---|---|
| Component names | No string/xref proof for yaw vs pitch vs forward on `local_d0..c4` |
| `local_d4` product meaning | Arg0 to `FUN_0091a5f0` only; not FOV-proven |
| Combat look matrix | Multi-branch mode tables under `+0xf5` / `+0x6b9` / `DAT_00d1b21b` incomplete |
| `FUN_0091a5f0` dual | Not in camera residual scope; CF as apply site only |
| Skills / airborne | UF-003 remainder — different SECTIONs |
